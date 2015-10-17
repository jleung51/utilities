/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-14
 *
 * This C program contains the implementation of a recursive merge sort
 * algorithm on an array of integers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

// Only for use by merge_sort().
// This function merges two sorted arrays to create a single array (in the
// memory spaces of the original arrays) with elements from least to greatest.
// array1 and array2 must be in consecutive memory spaces - i.e. two sections
// of the same array.
static void merge_arrays( int* array1, unsigned int len1,
                          int* array2, unsigned int len2 );



// Only for use by merge_sort().
// This function merges two sorted arrays to create a single array (in the
// memory spaces of the original arrays) with elements from least to greatest.
// array1 and array2 must be in consecutive memory spaces - i.e. two sections
// of the same array.
static void merge_arrays( int* array1, unsigned int len1,
                          int* array2, unsigned int len2 )
{
  int* array_final = array1;
  int len_final = len1 + len2;
  int array_copy[len_final];

  int i = 0;
  while( len1 > 0 && len2 > 0 )
  {
    if( array1[0] < array2[0] )  // Insert element from array1 into array_copy
    {
      array_copy[i] = array1[0];
      array1 += 1;
      len1--;
    }
    else  // Insert element from array2 into array_copy
    {
      array_copy[i] = array2[0];
      array2 += 1;
      len2--;
    }

    ++i;
  }

  // Leftover elements
  int j;
  for( j = 0; j < len1; ++j )
  {
    array_copy[i + j] = array1[j];
  }
  for( j = 0; j < len2; ++j )

  {
    array_copy[i + j] = array2[j];
  }

  for( j = 0; j < len_final; ++j )
  {
    array_final[j] = array_copy[j];
  }

  return;
}

// This function recursively sorts an array from least to greatest using the
// merge sort algorithm.
void merge_sort( int* array, unsigned int len )
{
  if( array == NULL )
  {
    printf( "Error: merge_sort() was given a null pointer.\n" );
    exit( 1 );
  }

  if( len <= 1 )
  {
    return;
  }

  int mid = len / 2;

  merge_sort( array,     mid );
  merge_sort( array+mid, len-mid );

  merge_arrays( array, mid, array+mid, len-mid );

  return;
}
