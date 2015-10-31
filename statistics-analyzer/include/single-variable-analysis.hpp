/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ header file contains functions which analyze a single dataset,
 * a vector of values.
 *
 */

#pragma once

#include <vector>

// This function sorts a given vector dataset.
// May be used on an already-sorted dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
template <class T>
void Sort( std::vector<T>& dataset );

// This function returns the mean of a vector dataset.
template <class T>
T Mean( const std::vector<T>& dataset );

// This function returns the mode of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T Mode( const std::vector<T>& dataset );

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

// This function returns a given quartile of a vector dataset.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
//   The quartile is not 1, 2, 3, or 4 (invalid_argument).
template <class T>
T Quartile( const std::vector<T>& dataset, unsigned int quartile_num );

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

// This function returns the IQR of a vector dataset.
// The 1.5 IQR rule is used.
// An exception is thrown if:
//   The dataset is empty (length_error)
//   The dataset is not sorted in ascending order (invalid_argument)
template <class T>
T InterQuartileRange( const std::vector<T>& dataset );

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
