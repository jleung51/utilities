/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-01
 *
 * This program contains functions which calculate and print the change required for a purchase.
 *
 */

#include <cmath>
#include <iomanip>
#include <iostream>

#include "change.hpp"

// This function prints the amount of a given denomination (bill or coin).
static void print_denomination( unsigned int amount, double denomination );

// This function prints the amount of a given denomination (bill or coin).
static void print_denomination( unsigned int amount, double denomination )
{
  if( amount == 0 )
  {
    return;
  }

  std::cout << amount ;

  if( denomination == 100 )
  {
    std::cout << " $100 bill" ;
  }
  else if( denomination == 50 )
  {
    std::cout << " $50 bill" ;
  }
  else if( denomination == 20 )
  {
    std::cout << " $20 bill" ;
  }
  else if( denomination == 10 )
  {
    std::cout << " $10 bill" ;
  }
  else if( denomination == 5 )
  {
    std::cout << " $5 bill" ;
  }
  else if( denomination == 2 )
  {
    std::cout << " toonie" ;
  }
  else if( denomination == 1 )
  {
    std::cout << " loonie" ;
  }
  else if( denomination == 0.25 )
  {
    std::cout << " quarter" ;
  }
  else if( denomination == 0.10 )
  {
    std::cout << " dime" ;
  }
  else if( denomination == 0.05 )
  {
    std::cout << " nickel" ;
  }
  else if( denomination == 0.01 )
  {
    if( amount == 1 )
    {
      std::cout << " penny" ;
    }
    else
    {
      std::cout << " pennies" ;
    }
  }
  else
  {
    std::cout << "Error: print_denomination() was given an invalid denomination (" << denomination\
                  << ").\nBugfix required.\n" ;
    exit( 2 );
  }

  if( amount > 1 && denomination != 0.01 )
  {
    std::cout << "s" ;
  }
  std::cout << "\n" ;

  return;
}

// This function displays the change necessary, if any, for a given purchase.
void return_change( double price, double money_given )
{

  if( price <= 0 )
  {
    std::cout << "Error: That is not a valid price.\n" ;
    exit( 1 );
  }
  else if( money_given < 0 )
  {
    std::cout << "That is not a valid amount for money given.\n" ;
    exit( 1 );
  }

  double change = money_given - price;

  if( change == 0 )
  {
    std::cout << "Exact change.\n" ;
  }
  else if( change < 0 )
  {
    change = 0 - change;

    std::cout << "Not enough money was given; $" ;
    std::cout << std::setprecision(2) << std::fixed << change ;  // Prints only two decimal places
    std::cout << " more is required.\n" ;
  }
  else
  {
    std::cout << "The change is $" ;
    std::cout << std::setprecision(2) << std::fixed << change ;  // Prints only two decimal places
    std::cout << ", which is:\n" ;

    double denominations[11] = { 100, 50, 20, 10, 5, 2, 1, 0.25, 0.10, 0.05, 0.01 };
    unsigned int leftover;
    unsigned int coins_bills;

    for( int i = 0; i < 11; i++ )
    {
      // Sets coins_bills to be the necessary amount of a specific denomination,
      // and sets change to the remaining change to be calculated.

      leftover = std::fmod( change, denominations[i] );
      coins_bills = ( change - leftover ) / denominations[i];
      change -= coins_bills * denominations[i];

      print_denomination( coins_bills, denominations[i] );
    }
  }

  return;
}
