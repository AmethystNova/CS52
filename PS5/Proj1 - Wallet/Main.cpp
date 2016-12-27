#include <iostream>
#include <string>
#include <cmath>
#include "Wallet.h"
using namespace std;

int main() {

	Wallet w;

/*CREATE THREE MAIN POSSIBILITIES:
1)BAL > PURCHASE
2) BAL < PURCHASE
3) BAL = PURCHASE

/**************************      ( 1 )      ***********************************************************/
	//EXPECTING ZEROES: DEFAULT CONSTRUCTOR INITIALIZES TO AN EMPTY WALLET
	cout << "POSSIBILITY 1: BAL > PURCHASE." << endl;

	cout << "Default constructor should yield an empty wallet: " << endl;
	cout << "d:" << w.getDollars();
	cout << " c:" << w.getCents() << endl << endl;
	
	//ADDS TO THE MY DOLL AMT
	cout << "visitATM function should load 50 dollars. " << endl;
	w.visitATMForCash(50);

	//SHOULD HAVE 50 DOLL
	cout << "d:" << w.getDollars();
	cout << " c:" << w.getCents() << endl << endl;

	//BAL > PURCH
	cout << "buying something BELOW YOUR MEANS: " << endl;
	if (w.canPayFor(25, 35)) {
		// you have enough to pay for it...
		w.payFor(25, 35);
		cout << "buying $25.35 worth..." << endl;
	}
	else
		cout << "too pricey!! " << endl;

	//You should still have money left
	cout << "Money after purchase: " << endl;
	cout << "d:" << w.getDollars();
	cout << " c:" << w.getCents() << endl << endl;

	cout << "***************************************************************" << endl << endl;


/************************************      ( 2 )     ************************************************/

	//BAL < PURCH
	//you should have $24.65
	// this time you won't have enough money: should say TOO PRICEY!

	cout << "POSSIBILITY 2: BAL < PURCHASE." << endl;

	cout << "Attempting to buy something above your means... " << endl << endl;
	if (w.canPayFor(100,40)) {
		// you have enough to pay for it...
		w.payFor(100,40);
		cout << "buying $100.40 worth..." << endl;
	}
	else
		cout << "TOO PRICEY!" << endl;
	cout << "Money should stay the same. Transaction never occured." << endl;
	cout << "d:" << w.getDollars();
	cout << " c:" << w.getCents() << endl << endl;

	cout << "***************************************************************" << endl << endl;


/****************************************************************************************************/
	//BAL = PURCH
	//you should have $24.65 beforehand
	//you should be able to undergo the transaction 
	//you should have $0.00 afterward.
	cout << "POSSIBILITY 2: BAL == PURCHASE." << endl;

	cout << "Attempting to buy something equal to your value. " << endl << endl;
	if (w.canPayFor(24, 65)) {
		w.payFor(24, 65);
		cout << "buying $24.65 worth..." << endl; }
	else
		cout << "TOO PRICEY!!" << endl;
	
	cout << "You should have an empty wallet!! " << endl;

	cout << "d:" << w.getDollars();
	cout << " c:" << w.getCents() << endl << endl;
	cout << "***************************************************************" << endl << endl;


/***************** FINALLY, TESTING PARAMETRIZED CONSTRUCTOR ********************************************/
	Wallet w2(100,20);
	cout << "The parametrized constructor should yield 100 dollars and 20 cents. " << endl;
	cout << "d:" << w2.getDollars();
	cout << " c:" << w2.getCents() << endl << endl;

	return (0); 
}
