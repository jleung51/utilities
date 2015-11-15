/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-31
 *
 * This C++ program tests the statistical analysis functions/classes.
 *
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "print-data-structures.hpp"
#include "../include/merge-sort.hpp"
#include "../include/single-variable-analysis.hpp"
#include "../include/multi-variable-analysis.hpp"
#include "../include/statistics-analyzer.hpp"

int main()
{
  srand( time(0) );  // Seeding random number generator

  std::cout << std::endl
            << "TESTING SINGLE VARIABLE ANALYSIS:"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::cout << "Sort():"
            << std::endl;

  std::vector<int> dataset_sort;
  for( unsigned int i = 0; i < 10; ++i )
  {
    dataset_sort.push_back( rand() % 100 );
  }

  std::cout << "Before sorting, the randomly generated dataset is ";
  PrintHorizontal( dataset_sort.begin(), dataset_sort.end() );
  std::cout << std::endl;

  Sort( dataset_sort );

  std::cout << "After sorting,  the randomly generated dataset is ";
  PrintHorizontal( dataset_sort.begin(), dataset_sort.end() );
  std::cout << std::endl
            << std::endl;


  std::cout << "Mean() and Mean_ToFloat():"
            << std::endl;

  std::vector<int> dataset_mean;
  for( unsigned int i = 0; i < 3; ++i )
  {
    dataset_mean.push_back( rand() % 5 );
  }

  std::cout << "The mean of the randomly generated integer dataset ";
  PrintHorizontal( dataset_mean.begin(), dataset_mean.end() );
  std::cout << " is "
            << Mean( dataset_mean )
            << " as an integer, and "
            << Mean_ToFloat( dataset_mean )
            << " as a float value."
            << std::endl
            << std::endl;


  std::cout << "Mode():"
            << std::endl;

  std::vector<int> dataset_mode;
  dataset_mode.push_back( 1 );
  dataset_mode.push_back( 1 );
  dataset_mode.push_back( 2 );
  dataset_mode.push_back( 3 );
  dataset_mode.push_back( 3 );
  dataset_mode.push_back( 3 );
  dataset_mode.push_back( 5 );
  dataset_mode.push_back( 5 );
  dataset_mode.push_back( 7 );
  dataset_mode.push_back( 7 );
  dataset_mode.push_back( 7 );

  std::vector<int> dataset_mode_modes;
  Mode( dataset_mode, dataset_mode_modes );

  std::cout << "The modes of the dataset ";
  PrintHorizontal( dataset_mode.begin(), dataset_mode.end() );
  std::cout << " are ";
  PrintHorizontal( dataset_mode_modes.begin(), dataset_mode_modes.end() );
  std::cout << "."
            << std::endl
            << std::endl;


  std::cout << "Median():"
            << std::endl;

  std::vector<int> dataset_median_odd;
  for( unsigned int i = 0; i < 5; ++i )
  {
    dataset_median_odd.push_back( i );
  }

  std::vector<int> dataset_median_even;
  for( unsigned int i = 0; i < 4; ++i )
  {
    dataset_median_even.push_back( i*2 );
  }

  std::cout << "The median of the dataset ";
  PrintHorizontal( dataset_median_odd.begin(), dataset_median_odd.end() );
  std::cout << " is "
            << Median( dataset_median_odd )
            << "."
            << std::endl;

  std::cout << "The median of the dataset ";
  PrintHorizontal( dataset_median_even.begin(), dataset_median_even.end() );
  std::cout << " is "
            << Median( dataset_median_even )
            << "."
            << std::endl
            << std::endl;


  std::cout << "Quartile() and Quartile_ToFloat():"
            << std::endl;

  std::vector<int> dataset_quartile_7;
  for( unsigned int i = 0 ; i < 7; ++i )
  {
    dataset_quartile_7.push_back( i );
  }

  std::cout << "From the dataset ";
  PrintHorizontal( dataset_quartile_7.begin(), dataset_quartile_7.end() );
  std::cout << ":"
            << std::endl;

  std::cout << "  Q1 = "
            << Quartile( dataset_quartile_7, 1 )
            << std::endl;
  std::cout << "  Q2 (median) = "
            << Quartile( dataset_quartile_7, 2 )
            << std::endl;
  std::cout << "  Q3 = "
            << Quartile( dataset_quartile_7, 3 )
            << std::endl
            << std::endl;

  std::vector<int> dataset_quartile_10;
  for( unsigned int i = 0 ; i < 10; ++i )
  {
    dataset_quartile_10.push_back( i );
  }

  std::cout << "From the dataset ";
  PrintHorizontal( dataset_quartile_10.begin(), dataset_quartile_10.end() );
  std::cout << ":"
            << std::endl;

  std::cout << "  Q1 = "
            << Quartile_ToFloat( dataset_quartile_10, 1 )
            << std::endl;
  std::cout << "  Q2 (median) = "
            << Quartile_ToFloat( dataset_quartile_10, 2 )
            << std::endl;
  std::cout << "  Q3 = "
            << Quartile_ToFloat( dataset_quartile_10, 3 )
            << std::endl
            << std::endl;

  return 0;
}
