/*
 *
 * Authors: Jeffrey Leung
 * Last edited: 2015-10-25
 *
 * This C++ header file contains a function which calculates all permutations of
 * a given set of characters.
 *
 */

#pragma once

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
              const bool permute_subseqs );
