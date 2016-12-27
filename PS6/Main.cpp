#include <iostream>
#include <string>
#include "FlashDrive.h"
using namespace std;
using namespace cs52;


void main()
{
	cs52::FlashDrive drive1(10, 0, false);
	cs52::FlashDrive drive2(20, 0, false);

	drive1.plugIn();
	std :: cout << "This should return as TRUE: " << drive1.isPluggedIn() << std::endl;
	drive1.formatDrive();
	
	drive1.writeData(5);
	std :: cout << "This should return as 5: " << drive1.getUsed() << std::endl;

	drive1.pullOut();
	std :: cout << "This should return as FALSE: " << drive1.isPluggedIn() << std::endl << std::endl;

	drive2.plugIn();
	drive2.formatDrive();
	drive2.writeData(1);
	drive2.pullOut();

	cs52::FlashDrive combined = drive1 + drive2;
	cout << "combined drive's filled to " << combined.getUsed() << endl;
	cout << "its capacity is " << combined.getCapacity() << endl;
	cout << "Is it plugged in by default? " << combined.isPluggedIn() << endl << endl;

	cs52::FlashDrive other = combined - drive1;
	cout << "other(diff)'s filled to " << other.getUsed() << endl;
	cout << "its capacity is " << other.getCapacity() << endl;
	cout << "Is it plugged in by default? " << other.isPluggedIn() << endl << endl;


	if (combined > other) {
		cout << "looks like combined is bigger than other..." << endl;
	}
	else {
		cout << "this should not print" << endl;
		cout << "looks like other is bigger..." << endl;
	}

	if (drive2 > other) {
		cout << "looks like drive2 is bigger than other..." << endl;
	}
	else {
		cout << "looks like other is bigger than drive 2..." << endl;
	}

	if (drive2 < drive1) {
		cout << "looks like drive2 is smaller than drive1..." << endl;
	}
	else {
		cout << "looks like drive1 is smaller than drive2..." << endl;
	}

}//END OF MAIN