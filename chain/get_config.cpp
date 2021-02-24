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

#include <graphene/chain/get_config.hpp>
#include <graphene/chain/config.hpp>
#include <graphene/protocol/types.hpp>

namespace graphene { namespace chain {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

   result[ "GRAPHENE_SYMBOL" ] = GRAPHENE_SYMBOL;
   result[ "GRAPHENE_ADDRESS_PREFIX" ] = GRAPHENE_ADDRESS_PREFIX;
   result[ "GRAPHENE_MIN_ACCOUNT_NAME_LENGTH" ] = GRAPHENE_MIN_ACCOUNT_NAME_LENGTH;
   result[ "GRAPHENE_MAX_ACCOUNT_NAME_LENGTH" ] = GRAPHENE_MAX_ACCOUNT_NAME_LENGTH;
   result[ "GRAPHENE_MIN_ASSET_SYMBOL_LENGTH" ] = GRAPHENE_MIN_ASSET_SYMBOL_LENGTH;
   result[ "GRAPHENE_MAX_ASSET_SYMBOL_LENGTH" ] = GRAPHENE_MAX_ASSET_SYMBOL_LENGTH;
   result[ "GRAPHENE_MAX_SHARE_SUPPLY" ] = GRAPHENE_MAX_SHARE_SUPPLY;
   result[ "GRAPHENE_MAX_SIG_CHECK_DEPTH" ] = GRAPHENE_MAX_SIG_CHECK_DEPTH;
   result[ "GRAPHENE_MIN_TRANSACTION_SIZE_LIMIT" ] = GRAPHENE_MIN_TRANSACTION_SIZE_LIMIT;
   result[ "GRAPHENE_MIN_BLOCK_INTERVAL" ] = GRAPHENE_MIN_BLOCK_INTERVAL;
   result[ "GRAPHENE_MAX_BLOCK_INTERVAL" ] = GRAPHENE_MAX_BLOCK_INTERVAL;
   result[ "GRAPHENE_DEFAULT_BLOCK_INTERVAL" ] = GRAPHENE_DEFAULT_BLOCK_INTERVAL;
   result[ "GRAPHENE_DEFAULT_MAX_TRANSACTION_SIZE" ] = GRAPHENE_DEFAULT_MAX_TRANSACTION_SIZE;
   result[ "GRAPHENE_DEFAULT_MAX_BLOCK_SIZE" ] = GRAPHENE_DEFAULT_MAX_BLOCK_SIZE;
   result[ "GRAPHENE_DEFAULT_MAX_TIME_UNTIL_EXPIRATION" ] = GRAPHENE_DEFAULT_MAX_TIME_UNTIL_EXPIRATION;
   result[ "GRAPHENE_DEFAULT_MAINTENANCE_INTERVAL" ] = GRAPHENE_DEFAULT_MAINTENANCE_INTERVAL;
   result[ "GRAPHENE_DEFAULT_MAINTENANCE_SKIP_SLOTS" ] = GRAPHENE_DEFAULT_MAINTENANCE_SKIP_SLOTS;
   result[ "GRAPHENE_MIN_UNDO_HISTORY" ] = GRAPHENE_MIN_UNDO_HISTORY;
   result[ "GRAPHENE_MAX_UNDO_HISTORY" ] = GRAPHENE_MAX_UNDO_HISTORY;
   result[ "GRAPHENE_MIN_BLOCK_SIZE_LIMIT" ] = GRAPHENE_MIN_BLOCK_SIZE_LIMIT;
   result[ "GRAPHENE_BLOCKCHAIN_PRECISION" ] = GRAPHENE_BLOCKCHAIN_PRECISION;
   result[ "GRAPHENE_BLOCKCHAIN_PRECISION_DIGITS" ] = GRAPHENE_BLOCKCHAIN_PRECISION_DIGITS;
   result[ "GRAPHENE_100_PERCENT" ] = GRAPHENE_100_PERCENT;
   result[ "GRAPHENE_1_PERCENT" ] = GRAPHENE_1_PERCENT;
   result[ "GRAPHENE_MAX_MARKET_FEE_PERCENT" ] = GRAPHENE_MAX_MARKET_FEE_PERCENT;
   result[ "GRAPHENE_DEFAULT_FORCE_SETTLEMENT_DELAY" ] = GRAPHENE_DEFAULT_FORCE_SETTLEMENT_DELAY;
   result[ "GRAPHENE_DEFAULT_FORCE_SETTLEMENT_OFFSET" ] = GRAPHENE_DEFAULT_FORCE_SETTLEMENT_OFFSET;
   result[ "GRAPHENE_DEFAULT_FORCE_SETTLEMENT_MAX_VOLUME" ] = GRAPHENE_DEFAULT_FORCE_SETTLEMENT_MAX_VOLUME;
   result[ "GRAPHENE_DEFAULT_PRICE_FEED_LIFETIME" ] = GRAPHENE_DEFAULT_PRICE_FEED_LIFETIME;
   result[ "GRAPHENE_DEFAULT_MAX_AUTHORITY_MEMBERSHIP" ] = GRAPHENE_DEFAULT_MAX_AUTHORITY_MEMBERSHIP;
   result[ "GRAPHENE_DEFAULT_MAX_ASSET_WHITELIST_AUTHORITIES" ] = GRAPHENE_DEFAULT_MAX_ASSET_WHITELIST_AUTHORITIES;
   result[ "GRAPHENE_DEFAULT_MAX_ASSET_FEED_PUBLISHERS" ] = GRAPHENE_DEFAULT_MAX_ASSET_FEED_PUBLISHERS;
   result[ "GRAPHENE_COLLATERAL_RATIO_DENOM" ] = GRAPHENE_COLLATERAL_RATIO_DENOM;
   result[ "GRAPHENE_MIN_COLLATERAL_RATIO" ] = GRAPHENE_MIN_COLLATERAL_RATIO;
   result[ "GRAPHENE_MAX_COLLATERAL_RATIO" ] = GRAPHENE_MAX_COLLATERAL_RATIO;
   result[ "GRAPHENE_DEFAULT_MAINTENANCE_COLLATERAL_RATIO" ] = GRAPHENE_DEFAULT_MAINTENANCE_COLLATERAL_RATIO;
   result[ "GRAPHENE_DEFAULT_MAX_SHORT_SQUEEZE_RATIO" ] = GRAPHENE_DEFAULT_MAX_SHORT_SQUEEZE_RATIO;
   result[ "GRAPHENE_DEFAULT_MAX_WITNESSES" ] = GRAPHENE_DEFAULT_MAX_WITNESSES;
   result[ "GRAPHENE_DEFAULT_MAX_COMMITTEE" ] = GRAPHENE_DEFAULT_MAX_COMMITTEE;
   result[ "GRAPHENE_DEFAULT_MAX_PROPOSAL_LIFETIME_SEC" ] = GRAPHENE_DEFAULT_MAX_PROPOSAL_LIFETIME_SEC;
   result[ "GRAPHENE_DEFAULT_COMMITTEE_PROPOSAL_REVIEW_PERIOD_SEC" ] = GRAPHENE_DEFAULT_COMMITTEE_PROPOSAL_REVIEW_PERIOD_SEC;
   result[ "GRAPHENE_DEFAULT_NETWORK_PERCENT_OF_FEE" ] = GRAPHENE_DEFAULT_NETWORK_PERCENT_OF_FEE;
   result[ "GRAPHENE_DEFAULT_LIFETIME_REFERRER_PERCENT_OF_FEE" ] = GRAPHENE_DEFAULT_LIFETIME_REFERRER_PERCENT_OF_FEE;
   result[ "GRAPHENE_DEFAULT_CASHBACK_VESTING_PERIOD_SEC" ] = GRAPHENE_DEFAULT_CASHBACK_VESTING_PERIOD_SEC;
   result[ "GRAPHENE_DEFAULT_CASHBACK_VESTING_THRESHOLD" ] = GRAPHENE_DEFAULT_CASHBACK_VESTING_THRESHOLD;
   result[ "GRAPHENE_DEFAULT_BURN_PERCENT_OF_FEE" ] = GRAPHENE_DEFAULT_BURN_PERCENT_OF_FEE;
   result[ "GRAPHENE_DEFAULT_MAX_ASSERT_OPCODE" ] = GRAPHENE_DEFAULT_MAX_ASSERT_OPCODE;
   result[ "GRAPHENE_DEFAULT_FEE_LIQUIDATION_THRESHOLD" ] = GRAPHENE_DEFAULT_FEE_LIQUIDATION_THRESHOLD;
   result[ "GRAPHENE_DEFAULT_ACCOUNTS_PER_FEE_SCALE" ] = GRAPHENE_DEFAULT_ACCOUNTS_PER_FEE_SCALE;
   result[ "GRAPHENE_DEFAULT_ACCOUNT_FEE_SCALE_BITSHIFTS" ] = GRAPHENE_DEFAULT_ACCOUNT_FEE_SCALE_BITSHIFTS;
   result[ "GRAPHENE_MAX_WORKER_NAME_LENGTH" ] = GRAPHENE_MAX_WORKER_NAME_LENGTH;
   result[ "GRAPHENE_MAX_URL_LENGTH" ] = GRAPHENE_MAX_URL_LENGTH;
   result[ "GRAPHENE_CORE_ASSET_CYCLE_RATE" ] = GRAPHENE_CORE_ASSET_CYCLE_RATE;
   result[ "GRAPHENE_CORE_ASSET_CYCLE_RATE_BITS" ] = GRAPHENE_CORE_ASSET_CYCLE_RATE_BITS;
   result[ "GRAPHENE_DEFAULT_WITNESS_PAY_PER_BLOCK" ] = GRAPHENE_DEFAULT_WITNESS_PAY_PER_BLOCK;
   result[ "GRAPHENE_DEFAULT_WITNESS_PAY_VESTING_SECONDS" ] = GRAPHENE_DEFAULT_WITNESS_PAY_VESTING_SECONDS;
   result[ "GRAPHENE_DEFAULT_WORKER_BUDGET_PER_DAY" ] = GRAPHENE_DEFAULT_WORKER_BUDGET_PER_DAY;
   result[ "GRAPHENE_COMMITTEE_ACCOUNT" ] = fc::variant(GRAPHENE_COMMITTEE_ACCOUNT, GRAPHENE_MAX_NESTED_OBJECTS);
   result[ "GRAPHENE_WITNESS_ACCOUNT" ] = fc::variant(GRAPHENE_WITNESS_ACCOUNT, GRAPHENE_MAX_NESTED_OBJECTS);
   result[ "GRAPHENE_RELAXED_COMMITTEE_ACCOUNT" ] = fc::variant(GRAPHENE_RELAXED_COMMITTEE_ACCOUNT, GRAPHENE_MAX_NESTED_OBJECTS);
   result[ "GRAPHENE_NULL_ACCOUNT" ] = fc::variant(GRAPHENE_NULL_ACCOUNT, GRAPHENE_MAX_NESTED_OBJECTS);
   result[ "GRAPHENE_TEMP_ACCOUNT" ] = fc::variant(GRAPHENE_TEMP_ACCOUNT, GRAPHENE_MAX_NESTED_OBJECTS);

   return result;
}

namespace graphene { namespace chain {
namespace detail {
   // TODO review and remove code below and links to it after hf_1268
   void check_asset_options_hf_1268(const fc::time_point_sec& block_time, const asset_options& options)
   {
      if( block_time < HARDFORK_1268_TIME )
      {
         FC_ASSERT( !options.extensions.value.reward_percent.valid(),
            "Asset extension reward percent is only available after HARDFORK_1268_TIME!");

         FC_ASSERT( !options.extensions.value.whitelist_market_fee_sharing.valid(),
            "Asset extension whitelist_market_fee_sharing is only available after HARDFORK_1268_TIME!");
      }
   }
}

void_result asset_create_evaluator::do_evaluate( const asset_create_operation& op )
{ try {

   database& d = db();

   const auto& chain_parameters = d.get_global_properties().parameters;
   FC_ASSERT( op.common_options.whitelist_authorities.size() <= chain_parameters.maximum_asset_whitelist_authorities );
   FC_ASSERT( op.common_options.blacklist_authorities.size() <= chain_parameters.maximum_asset_whitelist_authorities );

   detail::check_asset_options_hf_1268(d.head_block_time(), op.common_options);

   // Check that all authorities do exist
   for( auto id : op.common_options.whitelist_authorities )
      d.get_object(id);
   for( auto id : op.common_options.blacklist_authorities )
      d.get_object(id);

   auto& asset_indx = d.get_index_type<asset_index>().indices().get<by_symbol>();
   auto asset_symbol_itr = asset_indx.find( op.symbol );
   FC_ASSERT( asset_symbol_itr == asset_indx.end() );

   if( d.head_block_time() > HARDFORK_385_TIME )
   {
      auto dotpos = op.symbol.rfind( '.' );
      if( dotpos != std::string::npos )
      {
         auto prefix = op.symbol.substr( 0, dotpos );
         auto asset_symbol_itr = asset_indx.find( prefix );
         FC_ASSERT( asset_symbol_itr != asset_indx.end(), "Asset ${s} may only be created by issuer of ${p}, but ${p} has not been registered",
                    ("s",op.symbol)("p",prefix) );
         FC_ASSERT( asset_symbol_itr->issuer == op.issuer, "Asset ${s} may only be created by issuer of ${p}, ${i}",
                    ("s",op.symbol)("p",prefix)("i", op.issuer(d).name) );
      }
   }
   else
   {
      auto dotpos = op.symbol.find( '.' );
      if( dotpos != std::string::npos )
          wlog( "Asset ${s} has a name which requires hardfork 385", ("s",op.symbol) );
   }

   if( op.bitasset_opts )
   {
      const asset_object& backing = op.bitasset_opts->short_backing_asset(d);
      if( backing.is_market_issued() )
      {
         const asset_bitasset_data_object& backing_bitasset_data = backing.bitasset_data(d);
         const asset_object& backing_backing = backing_bitasset_data.options.short_backing_asset(d);
         FC_ASSERT( !backing_backing.is_market_issued(),
                    "May not create a bitasset backed by a bitasset backed by a bitasset." );
         FC_ASSERT( op.issuer != GRAPHENE_COMMITTEE_ACCOUNT || backing_backing.get_id() == asset_id_type(),
                    "May not create a blockchain-controlled market asset which is not backed by CORE.");
      } else
         FC_ASSERT( op.issuer != GRAPHENE_COMMITTEE_ACCOUNT || backing.get_id() == asset_id_type(),
                    "May not create a blockchain-controlled market asset which is not backed by CORE.");
      FC_ASSERT( op.bitasset_opts->feed_lifetime_sec > chain_parameters.block_interval &&
                 op.bitasset_opts->force_settlement_delay_sec > chain_parameters.block_interval );
   }
   if( op.is_prediction_market )
   {
      FC_ASSERT( op.bitasset_opts );
      FC_ASSERT( op.precision == op.bitasset_opts->short_backing_asset(d).precision );
   }

   return void_result();
} FC_CAPTURE_AND_RETHROW( (op) ) }

} } // graphene::chain
