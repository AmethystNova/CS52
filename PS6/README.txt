																	PROBLEM SET #6 : FULLER FLASHDRIVE
NAME: Kimberly Hernandez
COURSE: CS52
DATE: 10/19/16

PURPOSE: This program should demonstrate the power of overloading operators to have class-specific meanings.  Given a pre-existing FlashDrive class, I was to 
		enhance it to support + , - , > , and  < (by making them FRIENDs).  

INPUT: The user may interact with a drive by plugging it in/out, writing/deleting data, and setting the capacity. This enhanced class can intake two instances of FlashDrive
		and combine (their capacities and used data), differentiate (their capacities and used data), a compare (their capacities).

OUTPUT: The output of + and - is another instance of the class with combined and differentiated (respectively) capacities and used data (that is automaticallly "plugged in"). The output of > and <
		is a boolean value that compares their capacities. The program is safeguarded to output an error message if any of the new instance's attributes are negative or illogical (used data is greater
		than capacity, for example). The safeguarded output also returns an empty FlashDrive with 0 capacity that is not plugged in. (like the default constructor)
