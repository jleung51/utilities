/*
 *
 * Authors: Jeffrey Leung
 * Last edited: 2015-09-27
 *
 * This C++ header file contains a function which returns all permutations of
 * a given set of characters.
 *
 */

#pragma once

// This function returns a pointer to a vector of strings stored in heap
// memory, which are the possible permutations of the given characters.
// User is responsible for freeing the allocated memory.
// An exception is thrown if:
//   possibilities is an empty string (invalid_argument)
std::vector<std::string>* Permute( std::string possibilities );
