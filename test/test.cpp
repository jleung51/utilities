/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-01
 *
 * This program contains a testing implementation of the functions in change.cpp.
 *
 */

#include <iostream>
#include <cmath>

#include "../change.hpp"

int main()
{
  float price;
  float money_given;

  std::cout << "Enter the price of the item: $" ;
  std::cin >> price ;

  std::cout << "Enter the money given: $" ;
  std::cin >> money_given ;

  std::cout << "\n" ;
  return_change( price, money_given );

  return 0;
}
