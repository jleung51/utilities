/*
 *
 * Authors: Jeffrey Leung
 * Last edited: 2015-11-03
 *
 * This C++ file contains functions which return all permutations of a given
 * set of characters.
 *
 */

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../include/merge_sort_vector.hpp"
#include "../include/permute.hpp"

// Static functions:
namespace
{

// Static function prototypes:

// Only for use by Permute().
// This static function returns all possible permutations into the
// permutations vector, as well as possible subsequence permutations if
// permute_subseqs is true.
// When first called, chars_current should be empty.
void PermuteHelper( std::vector<std::string>& permutations,
                    std::string chars_current,
                    std::string chars_remaining,
                    const bool permute_subseqs );

// This static function checks for any repeated items in the vector and
// removes them.
// An exception is thrown if:
//   v is given an empty vector (invalid_argument)
template <class T>
void RemoveVectorDuplicates( std::vector<T>& v );

// Static function implementations:

// Only for use by Permute().
// This static function returns all possible permutations into the
// permutations vector, as well as possible subsequence permutations if
// permute_subseqs is true.
// When first called, chars_current should be empty.
void PermuteHelper( std::vector<std::string>& permutations,
                    std::string chars_current,
                    std::string chars_remaining,
                    const bool permute_subseqs )
{
  if( chars_remaining.size() > 0 )
  {
    std::string chars_current_new;
    std::string chars_remaining_new;
    
    for( unsigned int i = 0; i < chars_remaining.size(); ++i )
    {
      // Moves a character from the remaining characters to the current string
      chars_current_new   = chars_current + chars_remaining[i];
      chars_remaining_new = chars_remaining;
      chars_remaining_new.erase( i, 1 );
      
      PermuteHelper( permutations,
                     chars_current_new,
                     chars_remaining_new,
                     permute_subseqs );
    }
  }
  else if( !permute_subseqs &&
           chars_current.size() > 0 )
  {
    // If subsequences are not to permuted, this will only run when
    // the function has a complete permutation.
    permutations.push_back( chars_current );
  }
  
  if( permute_subseqs &&
      chars_current.size() > 0 )
  {
    // If subsequences are to be permuted, this will run any time
    // the function has a valid subsequence.
    permutations.push_back( chars_current );
  }
  return;
}

// This static function checks for any repeated items in the vector and
// removes them.
// An exception is thrown if:
//   v is given an empty vector (invalid_argument)
template <class T>
void RemoveVectorDuplicates( std::vector<T>& v )
{
  if( v.size() == 0 )
  {
    throw std::invalid_argument( "Error: RemoveVectorDuplicates() was given "\
      "an empty vector." );
  }
  
  MergeSortVector( v );
  
  for( unsigned int i = 0; i < v.size()-1; ++i )
  {
    if( v[i] == v[i+1] )
    {
      v.erase( v.begin() + i );
      --i;
    }
  }
  
  return;
}
  
} // Unnamed namespace


// Functions:

// This function calculates all possible permutations of the given characters
// (and their subsequences, if necessary) and places the results into the
// vector permutations (which should be empty at the start).
// If permute_subseqs is set to true, then the vector will also contain all
// possible permuted subsequences of the possiblities.
// An exception is thrown if:
//   permutations is a non-empty vector (invalid_argument)
//   possibilities is an empty string (invalid_argument)
void Permute( std::vector<std::string>& permutations,
              std::string possibilities,
              const bool permute_subseqs )
{
  if( !permutations.empty() )
  {
    throw std::invalid_argument( "Error: Permute() was given a non-empty "\
      "vector for permutations." );
  }
  else if( possibilities.size() == 0 )
  {
    throw std::invalid_argument( "Error: Permute() was given "\
      "an empty set of characters." );
  }
  
  std::string s;

  PermuteHelper( permutations, s, possibilities, permute_subseqs );
  
  try
  {
    RemoveVectorDuplicates<std::string>( permutations );
  }
  catch( std::exception& e )
  {
    std::cout << e.what()
              << std::endl;
  }
  
  return;
}
