#include <iostream>
#include <string>
#include "RecordPlayer.h"
using namespace std;

int main() {
//*******************************************************************************
	cout << "--Test 1--" << endl;
	RecordPlayer r;
	r.turnOn();
	r.affixPlatter("Barry Manilow I");
	r.plopNeedle();
	r.returnNeedle();
	r.turnOff();
//*******************************************************************************
	cout << "--Test 2--" << endl;
	RecordPlayer badr;
	badr.plopNeedle();
//*******************************************************************************
	cout << "--Test 3--" << endl;
	RecordPlayer badr1;
	badr1.turnOn();
	badr1.plopNeedle();
//********************************************************************************
	cout << "--Test 4--" << endl;
	RecordPlayer badr2;
	badr2.returnNeedle();
//*******************************************************************************
	cout << "--Test 5--" << endl;
	RecordPlayer badr3;
	badr3.turnOn();
	badr3.returnNeedle();
//********************************************************************************


	return(0);


}