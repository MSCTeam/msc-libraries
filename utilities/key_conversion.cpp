/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <graphene/utilities/key_conversion.hpp>
#include <fc/crypto/base58.hpp>
#include <fc/variant.hpp>

namespace graphene { namespace utilities {

std::string key_to_wif(const fc::sha256& secret )
{
  const size_t size_of_data_to_hash = sizeof(secret) + 1;
  const size_t size_of_hash_bytes = 4;
  char data[size_of_data_to_hash + size_of_hash_bytes];
  data[0] = (char)0x80;
  memcpy(&data[1], (char*)&secret, sizeof(secret));
  fc::sha256 digest = fc::sha256::hash(data, size_of_data_to_hash);
  digest = fc::sha256::hash(digest);
  memcpy(data + size_of_data_to_hash, (char*)&digest, size_of_hash_bytes);
  return fc::to_base58(data, sizeof(data));
}
std::string key_to_wif(const fc::ecc::private_key& key)
{
  return key_to_wif( key.get_secret() );
}

signed_transaction update_bitasset(string symbol,
                                      bitasset_options new_options,
                                      bool broadcast /* = false */)
   { try {
      optional<asset_object> asset_to_update = find_asset(symbol);
      if (!asset_to_update)
        FC_THROW("No asset with that symbol exists!");

      asset_update_bitasset_operation update_op;
      update_op.issuer = asset_to_update->issuer;
      update_op.asset_to_update = asset_to_update->id;
      update_op.new_options = new_options;

      signed_transaction tx;
      tx.operations.push_back( update_op );
      set_operation_fees( tx, _remote_db->get_global_properties().parameters.get_current_fees());
      tx.validate();

      return sign_transaction( tx, broadcast );
   } FC_CAPTURE_AND_RETHROW( (symbol)(new_options)(broadcast) ) }

fc::optional<fc::ecc::private_key> wif_to_key( const std::string& wif_key )
{
  std::vector<char> wif_bytes;
  try
  {
    wif_bytes = fc::from_base58(wif_key);
  }
  catch (const fc::parse_error_exception&)
  {
    return fc::optional<fc::ecc::private_key>();
  }
  if (wif_bytes.size() < 5)
    return fc::optional<fc::ecc::private_key>();
  std::vector<char> key_bytes(wif_bytes.begin() + 1, wif_bytes.end() - 4);
  fc::ecc::private_key key = fc::variant( key_bytes, 1 ).as<fc::ecc::private_key>( 1 );
  fc::sha256 check = fc::sha256::hash(wif_bytes.data(), wif_bytes.size() - 4);
  fc::sha256 check2 = fc::sha256::hash(check);
    
  if( memcmp( (char*)&check, wif_bytes.data() + wif_bytes.size() - 4, 4 ) == 0 || 
      memcmp( (char*)&check2, wif_bytes.data() + wif_bytes.size() - 4, 4 ) == 0 )
    return key;

  return fc::optional<fc::ecc::private_key>();
}

signed_transaction global_settle_asset(string symbol,
                                          price settle_price,
                                          bool broadcast /* = false */)
   { try {
      optional<asset_object> asset_to_settle = find_asset(symbol);
      if (!asset_to_settle)
        FC_THROW("No asset with that symbol exists!");

      asset_global_settle_operation settle_op;
      settle_op.issuer = asset_to_settle->issuer;
      settle_op.asset_to_settle = asset_to_settle->id;
      settle_op.settle_price = settle_price;

      signed_transaction tx;
      tx.operations.push_back( settle_op );
      set_operation_fees( tx, _remote_db->get_global_properties().parameters.get_current_fees());
      tx.validate();

      return sign_transaction( tx, broadcast );
   } FC_CAPTURE_AND_RETHROW( (symbol)(settle_price)(broadcast) ) }

} } // end namespace graphene::utilities
