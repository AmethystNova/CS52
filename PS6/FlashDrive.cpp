
#include <iostream>
#include <string>
#include "FlashDrive.h"
using namespace std;
using namespace cs52;

namespace cs52 {

	//constructors:
	//DEFAULT:
	FlashDrive::FlashDrive() {

		my_IsPluggedIn = 0;
		my_StorageCapacity = 0;
		my_StorageUsed = 0;

	}
	//PARAMETRIZED:
	//This seems lengthy, but I needed safeguards with respective error messaages in case a parametrized constructor with faulty inputs was given.
	//a case statement wouldn't work, even if it seems intuitive.
	FlashDrive::FlashDrive(int capacity, int used, bool pluggedIn) {

		bool okInput(1);
		//potentially unwanted stuff: 
		if (capacity < 0) {
			cout << "ERROR: Capacity can only be positive." << endl;
			okInput = 0;
			}

		if (used < 0) {
			cout << "ERROR: Used data can only be positive " << endl;
			okInput = 0;
		}
		
		if (used > capacity) {
			cout << "ERROR: The amount of used data cannot exceed the capacity." << endl;
			okInput = 0;
		}
		
		//actually building the FlashDrive. If valid input, fill it up accordingly. Else, create an empty one(like the 
		//default constructor would).
		if (okInput) {
			my_IsPluggedIn = pluggedIn;
			my_StorageCapacity = capacity;
			my_StorageUsed = used;
		}
		else {
			my_IsPluggedIn = 0;
			my_StorageCapacity = 0;
			my_StorageUsed = 0;
		}

	}
	//***************************************************************************************
//PLUG IN/PULL OUT

	void FlashDrive::plugIn() {

		if (my_IsPluggedIn)
			cout << "The FlashDrive is already plugged in! " << endl;
		else
		my_IsPluggedIn = 1;
	}

	void FlashDrive::pullOut() {

		if (my_IsPluggedIn)
			my_IsPluggedIn = 0;
		else
			cout << "The FlashDrive is already pulled out! " << endl;
	}
	//**************************************************************************************
	//MODIFYING THE FLASHDRIVE DATA: 
	
	//this intakes a user specified amount of data, and writes it to the flashdrive. It adjusts the
	//member variables accordingly. The flashdrive must be plugged in, and the amount added combined with
	//the storage used must NOT exceed the capacity.
	void FlashDrive::writeData(int amount) {
	
		if (my_IsPluggedIn) {
			if ((amount + my_StorageUsed) > my_StorageCapacity)
				cout << "ERROR: Adding desired data will exceed storage capacity. " << endl;
			else
				my_StorageUsed += amount;
		}
		else
			cout << "The FlashDrive must be plugged in in order to write to it! " << endl;
	}
	//*****************************************************************************************

	//this intakes a user specific amount of data, and deletes it from the flashdrive. It adjusts the
	//member variables accordingly.  The flashdrive must be plugged in, and the amount specified to 
	//be deleted cannot exceed the storage used.
	void FlashDrive::eraseData(int amount) {

		if (my_IsPluggedIn) {

			if ((my_StorageUsed - amount) < 0)
				cout << "ERROR: Deleting desired data results in negative storage. " << endl;
			else
				my_StorageUsed -= amount;
		}
		else 
			cout << "The FlashDrive must be plugged in in order to erase from it! " << endl;

	}
	//******************************************************************************************
	//This deletes all data from the flashdrive. 
	void FlashDrive::formatDrive() {
		my_StorageUsed = 0;
	} 


	int FlashDrive::getCapacity() {

		return(my_StorageCapacity);
	}
	/****************************************************************************************/
	void FlashDrive::setCapacity(int amount) {
		if (amount >= my_StorageUsed)
			my_StorageCapacity = amount;
		else
			cout << "ERROR: The formatted storage capacity must exceed or equate to the storage used." << endl;
	}
	/*****************************************************************************************/
	int FlashDrive::getUsed() {
		return(my_StorageUsed);
	}
	/*******************************************************************************************/
	void FlashDrive::setUsed(int amount) {

		if (amount >  my_StorageCapacity)
			cout << "ERROR: The amount of used data cannot exceed the storage capacity." << endl;
		else
			my_StorageUsed = amount;
	}

	//this returns true if the flashdrive is plugged in.
	bool FlashDrive::isPluggedIn() {
		return(my_IsPluggedIn);
	}
	/**************************************************************************************************/

	//This overloads the " + " operator.  This intakes two flashdrives and returns a new instance spawned with 
	//combined capacities and combined storages, that is plugged in.
	
	FlashDrive operator +(const FlashDrive& flash1, const FlashDrive& flash2) {

		FlashDrive temp = FlashDrive((flash1.my_StorageCapacity + flash2.my_StorageCapacity), (flash1.my_StorageUsed + flash2.my_StorageUsed), 1);
		return(temp);
	}
	/**************************************************************************************************/

	// This overloads the " - " operator.  It intakes two flashdrives and returns a new instance spawned with the difference in
	//attributes ( storage1 - storage1, used1 - used2 , etc). It is automatically "plugged in".

	FlashDrive operator -(const FlashDrive& flash1, const FlashDrive& flash2) {
		
		bool okInput(1);

		//If after the subtraction, there's negative capacity or storage, print an error message.  Set a flag that will create an empty 
		//instance of a FlashDrive instead of the faulty one. 

		if ((flash1.my_StorageCapacity - flash2.my_StorageCapacity) < 0) {
			cout << "ERROR: Capacity can only be positive." << endl;
			okInput = 0;
		}

		if ((flash1.my_StorageUsed - flash2.my_StorageUsed) < 0) {
			cout << "ERROR: Used data can only be positive " << endl;
			okInput = 0;
		}
		// if used > capacity : 
		if ((flash1.my_StorageUsed - flash2.my_StorageUsed) > (flash1.my_StorageCapacity - flash2.my_StorageCapacity)) {
			cout << "ERROR: The amount of used data cannot exceed the capacity." << endl;
			okInput = 0;
		}
		//if none of the potential pitfalls occured, return the appropriate "differentiated" FlashDrive. Else, return an empty one.
		if (okInput) {
			FlashDrive temp = FlashDrive((flash1.my_StorageCapacity - flash2.my_StorageCapacity), (flash1.my_StorageUsed - flash2.my_StorageUsed), 1);
			return(temp);
		}
		else
		{
			FlashDrive temp = FlashDrive();
			return(temp);
		}
	}
	/*****************************************************************************************************/

	//This overloaded operator compares the CAPACITIES between two flashdrives. If the leftmost has a greater capacity,
	//it returns TRUE.

	bool operator >(const FlashDrive& flash1, const FlashDrive& flash2) {

		if (flash1.my_StorageCapacity > flash2.my_StorageCapacity)
			return(1);
		else
			return(0);
	}
/************************************************************************************************************/

	//This overloaded operator compares the CAPACITIES between two flashdrives. If the rightmost has a greater capacity, 
	//it returns TURE.

	bool operator <(const FlashDrive& flash1, const FlashDrive& flash2) {

		if (flash1.my_StorageCapacity < flash2.my_StorageCapacity)
			return(1);
		else
			return(0);
	}

} //end of NAMESPACE definition
