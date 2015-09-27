/*
 *
 * Authors: Jeffrey Leung
 * Last edited: 2015-09-27
 *
 * This C++ file contains functions which return all permutations of a given
 * set of characters.
 *
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../include/permute.hpp"

// Static functions:

namespace
{

  // Static function prototypes:
  
  // Only for use by Permute().
  // This function returns all possible permutations into the
  // permutations vector.
  // When first called, chars_current should be empty.
  void PermuteHelper( std::vector<std::string>* permutations,
                      std::string chars_current,
                      std::string chars_remaining );

  // This function checks for any repeated items in the vector and
  // removes them.
  // An exception is thrown if:
  //   v is given an empty vector (invalid_argument)
  template <class T>
  void RemoveVectorDuplicates( std::vector<T>* v );
  
  // Only for use by RemoveVectorDuplicates().
  // This helper function removes any repeated items in the vector.
  // When first called, index should be 0.
  template <class T>
  void RemoveVectorDuplicatesHelper( std::vector<T>* v, unsigned int index );

  // Static function implementations:

  // Only for use by Permute().
  // This function returns all possible permutations into the
  // permutations vector.
  // When first called, chars_current should be empty.
  void PermuteHelper( std::vector<std::string>* permutations,
                      std::string chars_current,
                      std::string chars_remaining )
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
                       chars_remaining_new );
      }
    }
    else if( chars_current.size() > 0 )
    {
      permutations->push_back( chars_current );
    }
    
    return;
  }
  
  // This function checks for any repeated items in the vector and
  // removes them.
  // An exception is thrown if:
  //   v is given an empty vector (invalid_argument)
  template <class T>
  void RemoveVectorDuplicates( std::vector<T>* v )
  {
    if( v->size() == 0 )
    {
      throw std::invalid_argument( "Error: RemoveVectorDuplicates() was given "\
        "an empty vector." );
    }

    RemoveVectorDuplicatesHelper<std::string>( v, 0 );
    return;
  }
  
  // Only for use by RemoveVectorDuplicates().
  // This helper function removes any repeated items in the vector.
  // When first called, index should be 0.
  template <class T>
  void RemoveVectorDuplicatesHelper( std::vector<T>* v, unsigned int index )
  {
    unsigned int size = v->size();
    if( index > size )
    {
      return;
    }
    
    unsigned int i = index+1;
    while( i < size )
    {
      if( v->at(i) == v->at(index) )
      {
        v->erase( v->begin() + i );
        --size;
      }
      else
      {
        ++i;
      }
    }

    RemoveVectorDuplicatesHelper( v, index+1 );
    return;
  }
  
}

// Functions:

// This function returns a pointer to a vector of strings stored in heap
// memory, which are the possible permutations of the given characters.
// User is responsible for freeing the allocated memory.
// An exception is thrown if:
//   possibilities is an empty string (invalid_argument)
std::vector<std::string>* Permute( std::string possibilities )
{
  if( possibilities.size() == 0 )
  {
    throw std::invalid_argument( "Error: PermuteHelper() was given "\
      "an empty set of characters." );
  }

  std::vector<std::string>* permutations = new std::vector<std::string>;
  std::string s;

  PermuteHelper( permutations, s, possibilities );
  RemoveVectorDuplicates<std::string>( permutations );
  return permutations;
}
