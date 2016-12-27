#ifndef FLASHDRIVE
#define FLASHDRIVE
#include <iostream>
#include <string>
using namespace std;


namespace cs52 {

	class FlashDrive {
	public:
		//constructors:
		FlashDrive();
		FlashDrive(int capacity, int used, bool pluggedIn);

		void plugIn();
		void pullOut();

		void writeData(int amount);
		void eraseData(int amount);

		void formatDrive();

		int getCapacity();
		void setCapacity(int amount);

		int getUsed();
		void setUsed(int amount);

		bool isPluggedIn();

//OVERLOADED OPERATORS:
		friend FlashDrive operator +(const FlashDrive& flash1, const FlashDrive& flash2); 
		friend FlashDrive operator -(const FlashDrive& flash1, const FlashDrive& flash2);
		friend bool operator >(const FlashDrive& flash1, const FlashDrive& flash2);
		friend bool operator <(const FlashDrive& flash1, const FlashDrive& flash2);


	private: 
		int my_StorageCapacity;
		int my_StorageUsed;
		bool my_IsPluggedIn;

	}; //end of class declaration

} //end of namespace inclusion
#endif