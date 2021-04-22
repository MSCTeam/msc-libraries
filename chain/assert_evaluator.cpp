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

#include <graphene/chain/assert_evaluator.hpp>
#include <graphene/chain/block_summary_object.hpp>
#include <graphene/chain/database.hpp>

#include <sstream>

namespace graphene { namespace chain {

struct predicate_evaluator
{
   typedef void result_type;
   const database& db;

   predicate_evaluator( const database& d ):db(d){}

   void operator()( const  account_name_eq_lit_predicate& p )const
   {
      FC_ASSERT( p.account_id(db).name == p.name );
   }
   void operator()( const  asset_symbol_eq_lit_predicate& p )const
   {
      FC_ASSERT( p.asset_id(db).symbol == p.symbol );
   }
   void operator()( const block_id_predicate& p )const
   {
      FC_ASSERT( block_summary_id_type( block_header::num_from_id( p.id ) & 0xffff )(db).block_id == p.id );
   }
};

void_result assert_evaluator::do_evaluate( const assert_operation& o )
{ try {
   const database& _db = db();
   uint32_t skip = _db.get_node_properties().skip_flags;
   auto max_predicate_opcode = _db.get_global_properties().parameters.max_predicate_opcode;

   if( skip & database::skip_assert_evaluation )
      return void_result();

   for( const auto& p : o.predicates )
   {
      FC_ASSERT( p.which() >= 0 );
      FC_ASSERT( unsigned(p.which()) < max_predicate_opcode );
      p.visit( predicate_evaluator( _db ) );
   }
   return void_result();
} FC_CAPTURE_AND_RETHROW( (o) ) }

set<public_key_type, pubkey_comparator> account_member_index::get_key_members(const account_object& a)const
{
   set<public_key_type, pubkey_comparator> result;
   for( auto auth : a.owner.key_auths )
      result.insert(auth.first);
   for( auto auth : a.active.key_auths )
      result.insert(auth.first);
   result.insert( a.options.memo_key );
   return result;
}

void asset_create_evaluator::pay_fee()
{
   fee_is_odd = core_fee_paid.value & 1;
   core_fee_paid -= core_fee_paid.value/2;
   generic_evaluator::pay_fee();
}

void check_children_of_bitasset(database& d, const asset_update_bitasset_operation& op,
      const asset_object& new_backing_asset, bool after_hf_922_931)
{
   // no need to do these checks if the new backing asset is CORE
   if ( new_backing_asset.get_id() == asset_id_type() )
      return;

   // loop through all assets that have this asset as a backing asset
   const auto& idx = d.get_index_type<graphene::chain::asset_bitasset_data_index>()
         .indices()
         .get<by_short_backing_asset>();
   auto backed_range = idx.equal_range(op.asset_to_update);
   std::for_each( backed_range.first, backed_range.second,
         [after_hf_922_931, &new_backing_asset, &d, &op](const asset_bitasset_data_object& bitasset_data)
         {
            const auto& child = bitasset_data.asset_id(d);
            if ( after_hf_922_931 )
            {
               FC_ASSERT( child.get_id() != op.new_options.short_backing_asset,
                     "A BitAsset would be invalidated by changing this backing asset ('A' backed by 'B' backed by 'A')." );

               FC_ASSERT( child.issuer != GRAPHENE_COMMITTEE_ACCOUNT,
                     "A blockchain-controlled market asset would be invalidated by changing this backing asset." );

               FC_ASSERT( !new_backing_asset.is_market_issued(),
                     "A non-blockchain controlled BitAsset would be invalidated by changing this backing asset.");

            }
            else
            {
               if( child.get_id() == op.new_options.short_backing_asset )
               {
                  wlog( "Before hf-922-931, modified an asset to be backed by another, but would cause a continuous "
                        "loop. A cannot be backed by B which is backed by A." );
                  return;
               }

               if( child.issuer == GRAPHENE_COMMITTEE_ACCOUNT )
               {
                  wlog( "before hf-922-931, modified an asset to be backed by a non-CORE, but this asset "
                        "is a backing asset for a committee-issued asset. This occurred at block ${b}",
                        ("b", d.head_block_num()));
                  return;
               }
               else
               {
                  if ( new_backing_asset.is_market_issued() ) // a.k.a. !UIA
                  {
                     wlog( "before hf-922-931, modified an asset to be backed by an MPA, but this asset "
                           "is a backing asset for another MPA, which would cause MPA backed by MPA backed by MPA. "
                           "This occurred at block ${b}",
                           ("b", d.head_block_num()));
                     return;
                  }
               } // if child.issuer
            } // if hf 922/931
         } ); // end of lambda and std::for_each()
} // check_children_of_bitasset

void asset_create_evaluator::pay_fee()
{
   fee_is_odd = core_fee_paid.value & 1;
   core_fee_paid -= core_fee_paid.value/2;
   generic_evaluator::pay_fee();
}

void account_balance_object::adjust_balance(const asset& delta)
{
   assert(delta.asset_id == asset_type);
   balance += delta.amount;
   if( asset_type == asset_id_type() ) // CORE asset
      maintenance_flag = true;
}

void_result assert_evaluator::do_apply( const assert_operation& o )
{ try {
   // assert_operation is always a no-op
   return void_result();
} FC_CAPTURE_AND_RETHROW( (o) ) }

} } // graphene::chain
