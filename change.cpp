



#include <iostream>
#include <cmath>

#include "change.hpp"

static void print_denomination( unsigned int amount, float denomination );

/*

typedef enum
{
  bill_100,
  bill_50,
  bill_20,
  bill_10,
  bill_5,
  coin_2,
  coin_1,
  coin_0.25,
  coin_0.10,
  coin_0.05,
  coin_0.01
} denomination;


static void denomination_print( unsigned int bill_100,
                                unsigned int bill_50,
                                unsigned int bill_20,
                                unsigned int bill_10,
                                unsigned int bill_5,
                                unsigned int coin_2,
                                unsigned int coin_1,
                                unsigned int coin_0.25,
                                unsigned int coin_0.10,
                                unsigned int coin_0.05,
                                unsigned int coin_0.01 )
{
  std::cout << "The required change is: \n" ;

  if( bill_100 > 0 )
  {
    std::cout << bill_100 << " $100 bills\n" ;
  }

  if( bill_50 > 0 )
  {
    std::cout << bill_50 << " $50 bills\n" ;
  }

  if( bill_20 > 0 )
  {
    std::cout << bill_20 << " $20 bills\n" ;
  }

  if( bill_10 > 0 )
  {
    std::cout << bill_10 << " $10 bills\n" ;
  }

  if( bill_5 > 0 )
  {
    std::cout << bill_5 << " $5 bills\n" ;
  }

  if( coin_2 > 0 )
  {
    std::cout << coin_2 << " toonies\n" ;
  }

  if( coin_1 > 0 )
  {
    std::cout << coin_1 << " loonies\n" ;
  }

  if( coin_0.25 > 0 )
  {
    std::cout << coin_0.25 << " quarters\n" ;
  }

  if( coin_0.10 > 0 )
  {
    std::cout << coin_0.10 << " dimes\n" ;
  }

  if( coin_0.05 > 0 )
  {
    std::cout << coin_0.05 << " nickels\n" ;
  }

  if( coin_0.01 > 0 )
  {
    std::cout << coin_0.01 << " pennies\n" ;
  }

  return;
}
*/
static void print_denomination( unsigned int amount, float denomination )
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

void return_change( float price, float money_given )
{
  if( std::fmod( price, 0.01 ) != 0 )
  {
    std::cout << "That is not a valid price.\n" ;
  }
  else if( std::fmod( money_given, 0.01 ) != 0 )
  {
    std::cout << "That is not a valid amount for money given.\n" ;
  }

  float change = money_given - price;

  if( change == 0 )
  {
    std::cout << "Exact change given.\n" ;
  }
  else if( change < 0 )
  {
    change = abs(change);
    std::cout << "Not enough money was given; $" << change << " more is required.\n" ;
  }
  else
  {
    std::cout << "The change is $" << change << ", which is:\n" ;

    float denominations[11] = { 100, 50, 20, 10, 5, 2, 1, 0.25, 0.10, 0.05, 0.01 };
    unsigned int leftover;
    unsigned int coins_bills;

    for( int i = 0; i < 11; i++ )
    {
      leftover = std::fmod( money_given, denominations[i] );
      coins_bills = ( money_given - leftover ) / denominations[i];
      money_given = leftover;

      print_denomination( coins_bills, denominations[i] );
    }
  }

  return;
}
