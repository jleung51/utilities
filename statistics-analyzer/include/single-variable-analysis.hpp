/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-11-14
 *
 * This C++ header file contains functions which analyze a single dataset,
 * a vector of values.
 *
 */

#ifndef SINGLE_VARIABLE_ANALYSIS_HPP_
#define SINGLE_VARIABLE_ANALYSIS_HPP_

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "merge-sort.hpp"

// Function prototypes:

// This function sorts a given vector dataset.
// May be used on an already-sorted dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
void Sort( std::vector<T>& dataset );

// This function returns the mean of a vector dataset.
// Return value will be in the same type as the vector; for a float return
// value, use Mean_ToFloat().
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
T Mean( const std::vector<T>& dataset );

// This function returns the mean of a vector dataset as a float value.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
float Mean_ToFloat( const std::vector<T>& dataset );

// This function returns the modes of a vector dataset into a given vector
// reference.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The modes vector is non-empty.
template <class T>
void Mode( const std::vector<T>& dataset, std::vector<T>& modes );

// This function returns the median value of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Median( const std::vector<T>& dataset );

// This function returns the minimum value of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Minimum( const std::vector<T>& dataset );

// This function returns the maximum value of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Maximum( const std::vector<T>& dataset );

// This function returns the range of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Range( const std::vector<T>& dataset );

// This function returns a given quartile of a vector dataset.
// The median is not included in the calculation of the first or third
// quartiles.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The quartile is not 1, 2, or 3 (invalid_argument)
template <class T>
T Quartile( const std::vector<T>& dataset, unsigned int quartile_num );

// This function returns a given quartile of a vector dataset as a float value.
// The median is not included in the calculation of the first or third
// quartiles.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The quartile is not 1, 2, or 3 (invalid_argument)
template <class T>
float Quartile_ToFloat( const std::vector<T>& dataset,
                        unsigned int quartile_num );

// This function returns the IQR of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T InterQuartileRange( const std::vector<T>& dataset );

// This function returns the lower limit of a vector dataset.
// The 1.5 IQR rule is used.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
unsigned int LowerLimit( const std::vector<T>& dataset );

// This function returns the upper limit of a vector dataset.
// The 1.5 IQR rule is used.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
unsigned int UpperLimit( const std::vector<T>& dataset );

// This function returns the outliers of a vector dataset into a given vector.
// The 1.5 IQR rule is used.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The outliers vector is not empty (invalid_argument)
template <class T>
void Outliers( const std::vector<T>& dataset, std::vector<T>& outliers );

// This function returns the standard deviation of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
T StandardDeviation( const std::vector<T>& dataset );


// Static functions:
namespace
{

// Static function prototypes:

// This static function returns true if a given vector dataset is not sorted in
// ascending order, and false otherwise.
template <class T>
bool IsUnsorted( const std::vector<T>& dataset );

// Static function implementations:

// This static function returns true if a given vector dataset is not sorted in
// ascending order, and false otherwise.
template <class T>
bool IsUnsorted( const std::vector<T>& dataset )
{
  for( unsigned int i = 0; i < dataset.size()-1; ++i )
  {
    if( dataset[i] > dataset[i+1] )
    {
      return true;
    }
  }
  return false;
}

}  // Unnamed namespace


// Functions:

// This function sorts a given vector dataset.
// May be used on an already-sorted dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
void Sort( std::vector<T>& dataset )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Sort() was given an empty dataset." );
  }
  MergeSort<T>( dataset.begin(), dataset.end() );
  return;
}

// This function returns the mean of a vector dataset.
// Return value will be in the same type as the vector; for a float return
// value, use Mean_ToFloat().
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
T Mean( const std::vector<T>& dataset )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Mean() was given an empty dataset." );
  }

  T sum = 0;
  for( typename std::vector<T>::const_iterator i = dataset.begin();
       i != dataset.end();
       ++i )
  {
    sum += *i;
  }
  return sum / dataset.size();
}

// This function returns the mean of a vector dataset as a float value.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
float Mean_ToFloat( const std::vector<T>& dataset )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Mean_ToFloat() was given an empty "
      "dataset." );
  }

  std::vector<float> dataset_fl( dataset.begin(), dataset.end() );
  return Mean( dataset_fl );
}

// This function returns the modes of a vector dataset into a given vector
// reference.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The modes vector is non-empty.
template <class T>
void Mode( const std::vector<T>& dataset, std::vector<T>& modes )
{
  if( dataset.empty() )
  {
    throw std::invalid_argument( "Error: Mode() was given an empty dataset." );
  }
  if( IsUnsorted( dataset ) )
  {
    throw std::invalid_argument( "Error: Mode() was given an unsorted "\
      "dataset." );
  }
  if( !(modes.empty()) )
  {
    throw std::invalid_argument( "Error: Mode() was given a non-empty vector "
      "with which to return the modes." );
  }

  T current = dataset[0];
  unsigned int current_count = 1;
  unsigned int mode_count = 1;

  // Deals with the edge_case of the last element not being checked against
  // the other mode(s).
  typename std::vector<T>::const_iterator i_previous = dataset.begin();

  typename std::vector<T>::const_iterator i;
  for( i = ++dataset.begin(); i_previous != dataset.end(); ++i )
  {
    if( i != dataset.end() &&
        current == *i )
    {
      ++current_count;
    }
    else if( i == dataset.end() ||
             current != *i )
    {

      if( current_count > mode_count )  // New mode with greater count
      {
        mode_count = current_count;
        modes.resize( 0 );
        modes.push_back( current );
      }
      else if( current_count == mode_count )  // New mode with same count
      {
        modes.push_back( current );
      }

      if( i != dataset.end() )
      {
        current = *i;
      }
      i_previous = i;
      current_count = 1;

    }

  }

  return;
}

// This function returns the median value of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Median( const std::vector<T>& dataset )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Median() was given an empty dataset." );
  }
  if( IsUnsorted( dataset ) )
  {
    throw std::invalid_argument( "Error: Median() was given an unsorted " \
      "dataset." );
  }

  typename std::vector<T>::size_type size = dataset.size();

  if( size % 2 == 0 )  // Even number of elements; median requires calculation
  {
    return ( dataset[size/2 - 1] + dataset[size/2] ) / 2;
  }
  else  // Odd number of elements; median does not require calculation
  {
    return dataset[ floor(size/2.0) ];
  }
}

// This function returns a given quartile of a vector dataset.
// The median is not included in the calculation of the first or third
// quartiles.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The quartile is not 1, 2, or 3 (invalid_argument)
template <class T>
T Quartile( const std::vector<T>& dataset, unsigned int quartile_num )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Quartile() was given an empty dataset." );
  }
  if( IsUnsorted( dataset ) )
  {
    throw std::invalid_argument( "Error: Quartile() was given an unsorted " \
      "dataset." );
  }
  if( quartile_num < 1 || 3 < quartile_num )
  {
    throw std::invalid_argument( "Error: Quartile() was given an invalid "\
      "quartile number (must be 1, 2, or 3)." );
  }

  T quartile;
  typename std::vector<T>::size_type size = dataset.size();

  if( quartile_num == 1 )
  {
    std::vector<T> dataset_quartile( dataset.begin(),
                                     dataset.begin() + ceil(size/2.0 - 0.5) );
    quartile = Median( dataset_quartile );
  }
  else if( quartile_num == 2 )
  {
    quartile = Median( dataset );
  }
  else if( quartile_num == 3 )
  {
    std::vector<T> dataset_quartile( dataset.begin() + ceil(size/2.0),
                                     dataset.end()  );
    quartile = Median( dataset_quartile );
  }
  else
  {
    throw std::logic_error( "Error: Quartile() failed to catch an invalid " \
      "quartile number." );
  }

  return quartile;
}

// This function returns a given quartile of a vector dataset as a float value.
// The median is not included in the calculation of the first or third
// quartiles.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The quartile is not 1, 2, or 3 (invalid_argument)
template <class T>
float Quartile_ToFloat( const std::vector<T>& dataset,
                        unsigned int quartile_num )
{
  if( dataset.empty() )
  {
    throw std::length_error( "Error: Quartile_ToFloat() was given an empty " \
      "dataset." );
  }
  if( IsUnsorted( dataset ) )
  {
    throw std::invalid_argument( "Error: Quartile_ToFloat() was given an " \
      "unsorted dataset." );
  }
  if( quartile_num < 1 || 3 < quartile_num )
  {
    throw std::invalid_argument( "Error: Quartile_ToFloat() was given an " \
      "invalid quartile number (must be 1, 2, or 3)." );
  }

  std::vector<float> dataset_fl( dataset.begin(), dataset.end() );
  return Quartile( dataset_fl, quartile_num );
}

#endif // SINGLE_VARIABLE_ANALYSIS_HPP_
