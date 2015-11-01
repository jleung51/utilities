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
  
  
  std::cout << "Mean():"
            << std::endl;
  
  std::vector<int> dataset_mean;
  for( unsigned int i = 0; i < 3; ++i )
  {
    dataset_mean.push_back( rand() % 5 );
  }
  
  std::cout << "The mean of the randomly generated dataset ";
  PrintVectorHorizontal( dataset_mean );
  std::cout << " is "
            << Mean( dataset_mean )
            << "."
            << std::endl
            << std::endl;

  return 0;
}
