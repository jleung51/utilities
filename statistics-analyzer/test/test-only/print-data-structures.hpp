/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ header file contains functions which can be used to print
 * the contents of an array or vector.
 *
 */

#include <vector>

// This function prints the contents of a given array in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintArrayHorizontal( T* arr, unsigned int len );

// This function prints the contents of a given vector in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintVectorHorizontal( std::vector<T> v );
