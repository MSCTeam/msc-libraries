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

#include <graphene/egenesis/egenesis.hpp>

#include <fc/io/raw.hpp>

namespace graphene { namespace egenesis {

using namespace graphene::chain;

chain_id_type get_egenesis_chain_id()
{
   return chain_id_type();
}

void compute_egenesis_json( std::string& result )
{
   result = "";
}

void load_genesis(
   const boost::program_options::variables_map& options,
   egenesis_info& info
   )
{
   if( options.count("genesis-json") )
   {
      fc::path genesis_json_filename = get_path( options, "genesis-json" );
      std::cerr << "embed_genesis:  Reading genesis from file " << genesis_json_filename.preferred_string() << "\n";
      info.genesis_json = std::string();
      read_file_contents( genesis_json_filename, *info.genesis_json );
   }
   else
      info.genesis = graphene::app::detail::create_example_genesis();

   if( options.count("chain-id") )
   {
      std::string chain_id_str = options["chain-id"].as<std::string>();
      std::cerr << "embed_genesis:  Genesis ID from argument is " << chain_id_str << "\n";
      info.chain_id = chain_id_str;
   }
}

fc::sha256 get_egenesis_json_hash()
{
   return fc::sha256::hash( "" );
}

} }
