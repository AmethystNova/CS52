#ifndef WALLET
#define WALLET
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Wallet {
public:
//CONSTRUCTORS:
	Wallet();
	Wallet(int d, int c);

//GETTERS (IE ACCESSORS) :
	int getDollars();
	int getCents();

//MEMBER FUNCTIONS:
	bool canPayFor(int dollarAmount, int centsAmount);
	void payFor(int dollarAmount, int changeAmount);
	void visitATMForCash(int dollarAmount);
	
private:
	int my_Dollars;
	int my_Cents;

}; 

#endif
