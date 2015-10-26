/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-25
 *
 * This program contains a testing implementation of ReturnChange().
 *
 */

#include <iostream>
#include <cmath>

#include "../include/change.hpp"

int main()
{
  float price;
  float money_given;

  std::cout << "Enter the price of the item: $";
  std::cin >> price;

  std::cout << "Enter the money given: $";
  std::cin >> money_given;

  std::cout << "\n";
  ReturnChange( price, money_given );

  return 0;
}
