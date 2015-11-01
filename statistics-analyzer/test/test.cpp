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
#include "../include/merge-sort-vector.hpp"
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
  PrintVectorHorizontal( dataset_sort );
  std::cout << std::endl;
  
  Sort( dataset_sort );
  
  std::cout << "After sorting,  the randomly generated dataset is ";
  PrintVectorHorizontal( dataset_sort );
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
  PrintVectorHorizontal( dataset_mean );
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
  PrintVectorHorizontal( dataset_mode );
  std::cout << " are ";
  PrintVectorHorizontal( dataset_mode_modes );
  std::cout << "."
            << std::endl
            << std::endl;

  return 0;
}
