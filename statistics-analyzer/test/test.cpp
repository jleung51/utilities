/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-29
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
  std::cout << std::endl
            << "TESTING SINGLE VARIABLE ANALYSIS:"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::vector<int> dataset;
  for( unsigned int i = 0; i < 15; ++i )
  {
    dataset.push_back( std::rand() % 100 );
  }
  
  std::cout << "Sort():"
            << std::endl;
  
  std::cout << "Before sorting, the randomly generated dataset is ";
  PrintVectorHorizontal( dataset );
  std::cout << std::endl;
  
  Sort( dataset );
  
  std::cout << "After sorting,  the randomly generated dataset is ";
  PrintVectorHorizontal( dataset );
  std::cout << std::endl;
  
  std::cout << std::endl;
  return 0;
}
