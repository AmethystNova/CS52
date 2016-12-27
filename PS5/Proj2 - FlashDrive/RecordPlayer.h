#ifndef RECORDPLAYER
#define RECORDPLAYER
#include <iostream>
#include <string>
using namespace std;


class RecordPlayer {

public:
	RecordPlayer();

	void turnOn();
	void turnOff();
	bool isPoweredOn();

	void affixPlatter(string record);

	void plopNeedle();
	void returnNeedle();

private:
	bool my_isOn;
	string my_Record;
	bool my_NeedleIsOnTheRecord;
	bool my_RecordAffixed;

};

#endif
