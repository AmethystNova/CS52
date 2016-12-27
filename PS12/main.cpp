// ListDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "List.h"
#include "ListNode.h"

//global enum variable
enum CHOICE { PRINT1STLIST, PRINT2NDLIST, QUIT, INSERT, REMOVE, ISEMPTY, MAKEEMPTY, CONCATENATE, INSERTITH, REMOVEDUPS };
//function that returns a CHOICE and that takes in no parameters:
CHOICE menu();

int main(int argc, char* argv[])
//int main()
{
	using namespace cs52;
	using namespace std;

	List l;
	List l2;
	CHOICE c;
	int value, pos;
	int whichList;


	do {
		c = menu();
		//once c holds an enum type, ie CONCATENATE, INSERTITH... etc.
		//undergo a switch-case statement for that specific type. (ie if you picked PRINT2ND, it would print the 2nd list)
		switch (c) {

		case PRINT2NDLIST:
			cout << l2;
			break;

		case PRINT1STLIST:
			cout << l;
			break;

		case ISEMPTY:
			cout << "Which list? (1 or 2): ";
			cin >> whichList;

			if (whichList == 1) {
				if (l.isEmpty()) {
					cout << "list is empty" << endl;
				}
				else {
					cout << "list is not empty" << endl;
				}
			} //end of whichList ==1

			if (whichList == 2) {
				if (l2.isEmpty()) {
					cout << "list is empty" << endl;
				}
				else {
					cout << "list is not empty" << endl;
				}
			} //end of whichList == 2
			break;

		case MAKEEMPTY:
			cout << "Which list? (1 or 2): ";

			if (whichList == 1)
				l.makeEmpty();
			else
				l2.makeEmpty();
			break;

		case INSERT:
			cout << "enter an int to insert:";
			cin >> value;
			cout << "Which list? (1 or 2): ";
			cin >> whichList;

			if (whichList==1) 
			l.insert(value);
			
			if (whichList==2)
				l2.insert(value);

			break;

		case REMOVE:
			cout << "enter an int to remove:";
			cin >> value;
			cout << "Which list? (1 or 2): ";
			cin >> whichList;

			if (whichList == 1)
 			l.remove(value);

			if (whichList == 2)
				l2.remove(value);
			break;

		case CONCATENATE:
			cout << "doing concatenation" << endl;
			l.concatenate(l2);
			break;

		case INSERTITH:
			cout << "enter an int to insert:";
			cin >> value;
			cout << "enter the position to insert into:";
			cin >> pos;
			cout << "inserting into ith position" << endl;
			l.insertith(value, pos);
			break; 
		case REMOVEDUPS:
			cout << "removing duplicates" << endl;
			l.removeDups();
			break; 
		}
	} while (c != QUIT);

	return(0);
}

CHOICE menu() {
	using namespace std;
	char c;
	CHOICE result;


	//user picks a letter and it's stored into the variable "c". 
	cout << "i(S)empty (M)akeEmpty (I)nsert (R)emove Print(1)stList Print(2)ndList (C)concatentate I(N)sertIth R(E)moveDups (Q)uit:";
	cin >> c;
	//switch-case for "c". returns an enum type to the main program. 
	switch (c) {
	case 'C':
	case 'c':
		result = CONCATENATE;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'N':
	case 'n':
		result = INSERTITH;
		break;
	case 'R':
	case 'r':
		result = REMOVE;
		break;
	case '1':
		result = PRINT1STLIST;
		break;
	case '2':
		result = PRINT2NDLIST;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'E':
	case 'e':
		result = REMOVEDUPS;
		break;
	default:
		result = menu();
	}
	return(result);
}