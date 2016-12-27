
#include <iostream>
#include <string>
#include "RecordPlayer.h"
using namespace std;

//default constructor: 
RecordPlayer::RecordPlayer() {

	my_isOn = 0; 
	my_NeedleIsOnTheRecord = 0; 
	my_Record = ""; 
	my_RecordAffixed = 0; 
}

//if it's already on, cout err.
//if it's off, turn on.
void RecordPlayer :: turnOn() {

	if (my_isOn)
		cout << " You cannot turn on what's already on. Recordplayer was already on." << endl;
	else
		cout << "recordplayer is on..." << endl;
		my_isOn = 1;
}
//if it's on, turn off.
//if it's already off, cout err.
void RecordPlayer :: turnOff() {

	if (my_isOn) {
		my_isOn = 0;
		cout << "recordplayer is off..." << endl;
	}
	else
		cout << "Record player is already off!" << endl;
}
//self explanatory: return TRUE if the recordplayer is on.
bool RecordPlayer::isPoweredOn() {
	if (my_isOn)
		return(1);
	else
		return (0); 
}

//This places an album on the record player. If the needle is already on another record, display an error.
void RecordPlayer::affixPlatter(string record) {

	if (my_NeedleIsOnTheRecord)
		cout << "You must return the needle before affixing another album! " << endl;
	else {
	my_Record = record;
	cout << "recordplayer has album " << my_Record << endl;
	my_RecordAffixed = 1;
}
	
}
//conditions: recordplayer MUST BE ON. album must be affixed. the needle CANNOT BE on the record.
void RecordPlayer::plopNeedle() {

	if (my_isOn) {
		if (my_RecordAffixed) {
			if (my_NeedleIsOnTheRecord) //your needle is already on the record
				cout << "Your needle is already on the record! " << endl;
			else { //actually plop the needle!!!!
				cout << "recordplayer is playing album " << my_Record << endl;
				my_NeedleIsOnTheRecord = 1;
			}
		}
		else //if it's on, but there's no record
			cout << "You can't plop the needle without an album! " << endl;
	}
	else //if it's off
		cout << "You can't plop the needle without being powered on!" << endl;

}

//CONDITIONS: recordplayer MUST BE ON. Record MUST be affixed. The needle MUST BE on the record (or else, what're you gonna return?)
void RecordPlayer::returnNeedle() {

	if (my_isOn) {
		if (my_RecordAffixed) {
			if (my_NeedleIsOnTheRecord) {
				my_NeedleIsOnTheRecord = 0;
				cout << "recordplayer has stopped playing album... " << endl;

			}
			else
				cout << "The needle is already off the record!" << endl;
		}
		else
			cout << "You can't return the needle without an album! " << endl;
	}
	else
		cout << "You can't return the needle without being powered on! " << endl;
	

	}
