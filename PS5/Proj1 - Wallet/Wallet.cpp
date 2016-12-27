
#include <iostream>
#include <string>
#include <cmath>
#include "Wallet.h"
using namespace std;

//*********************************************************************
//CONSTRUCTORS:

//your wallet is by default empty!!!
Wallet::Wallet() {
	my_Dollars = 0;
	my_Cents = 0;
	}

Wallet::Wallet(int d, int c) {

	my_Dollars = d;
	my_Cents = c; 

}
//***********************************************************************

//GETTERS (IE ACCESSORS) :

//allows user to see an integer amount of dollars
int Wallet::getDollars() {

	return (my_Dollars); 
}
//allows user to see an integer amount of cents
int Wallet::getCents() {

	return(my_Cents); 
}

//********************************************************************
//MEMBER FUNCTIONS:

//intakes cost of item (in dollars and cents, discretely) and returns TRUE if user has
//enough to pay for it.
bool Wallet :: canPayFor(int dollarAmount, int centsAmount) {
	
	//for the sake of readability (at the cost of efficiency), I've spawned 2 local vars.
	double balance(0), purchase(0); 

	//unifying the fragmented integer components of both bal and purch.
	balance = (my_Dollars)+(my_Cents * .01); 
	purchase = (dollarAmount)+(centsAmount*.01);

	//self explanatory:
	if (balance >= purchase)
		return(1);
	else
		return(0); 
	
}

//once again, intakes cost of item in dollars and cents. Actually PAYS for item by reducing my_Dollars/my_Cents accordingly.
void Wallet::payFor(int dollarAmount, int changeAmount) {
	
	double balance(0), purchase(0), change(0);
	
	balance = (my_Dollars)+(my_Cents * .01);
	purchase = (dollarAmount)+(changeAmount*.01);
	
	//updating the balance
	balance -= purchase;

	//updating the integer components of balance:

	//returns a double that's automatically converted to int.
	my_Dollars = floor(balance);
	change = (balance - floor(balance)) * 100;
	change = ceil(change);
	my_Cents = change;
}

//Your visit to the ATM results in a respectve cash(dollar) increase.
void Wallet :: visitATMForCash(int dollarAmount) {

	my_Dollars += dollarAmount;

}
