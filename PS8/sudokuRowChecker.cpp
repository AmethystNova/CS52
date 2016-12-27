/*                                           ~~~~~   PROBLEM SET #8 : SUDOKU ROW CHECKER   ~~~~~~~
NAME: Kimberly Hernandez

COURSE: CS52

DATE: 11/10/16

PURPOSE: String data in C++ can be stored using the STRING class or as a c-string (a char array with a NULLCHAR denoting the end of the array).
		Oftentimes, the abstracted STRING class is alot easier to work with. This program should highlight the differences and similarities between the two.
		The SudokuRowChecker class stores both a STRING and a c-string of data (the ints that compose them are equal), and checks whether they're valid
		rows in a sudoku game (ie unique integers [1,9]) by processing the strings.

INPUT: The user can choose to set the data as a STRING or as a c-string. 

OUTPUT: If invoked, the class has a member function that returns the boolean TRUE if the string is indeed a valid sudoku row.

*/

#include <iostream>
#include <string>
#include <cstring>
#include "sudokuRowChecker.h"
using namespace std;

//default const.initializes string to full 0's, and then c-string array to full 0's
SudokuRowChecker :: SudokuRowChecker( ) {

	sudokuRow = "000000000" ; 
	loadArray();

};

//loads sudokuArray with string data
void SudokuRowChecker :: setData (char *s ) {

	strcpy(sudokuArray, s);


}

//intake string of string type. straightforward modification of attribute.
//function then loads sudoku array with string data.
void SudokuRowChecker :: setStringData( std::string s ) {

	sudokuRow = s; 
	loadArray();
}

//empty it out. set to initial status (FULL 0's). 
//Also set sudokuarray to full 0's.
void SudokuRowChecker ::  clear() {

	sudokuRow = "000000000" ;
	loadArray();

}

//CHECKS THE ARRAY, AND NOT THE STRING. 
//"meat" of the program. Automatically fails if string is not 9 chars. 
//each element must also be a unique digit [1,9].
bool SudokuRowChecker :: isValid( ) const
{
	int ones(0),twos(0),threes(0),fours(0),fives(0),sixes(0);
	int	sevens(0), eights(0), nines(0), i(0);


	//note that STRLEN does NOT count NULLCHAR!!
	//if the string is ANYTHING but 9, the input is invalid:
	if ( strlen(sudokuArray) != 9 ) {
		return(0);
	}
	
	//else, check for UNIQUENESS
	else
	{
		i=0; //initialize the index to 0 to start at first element.
		//iterate through entire array 
		while (sudokuArray[i] != '\0') {

			switch (sudokuArray[i]) {
			case '1' : ones++;
						if (ones > 1 )
							return (0);
						break;
			case '2': twos++;
					if (twos > 1 )
							return (0);
					break;
			case '3': threes++;
					if (threes > 1)
						return(0);
					break;
			case '4': fours++;
					if (fours >1 )
						return (0);
					break;
			case '5': fives++;
					if (fives > 1 ) 
						return(0);
					break;
			case '6': sixes++ ;
					if (sixes > 1)
						return (0);
					break;
			case '7': sevens++ ;
					if (sevens > 1 ) 
						return (0) ;
					break;
			case '8': eights++ ;
					if (eights > 1 )
						return (0) ;
					break;
			case '9': nines++;
					if (nines > 1 )
						return(0);
					break;
			default:
				//number is invalid, automatically exit.
				return(0);
			}//end SWITCH CASE block
		i++;
		} //end WHILE block

	}//end ELSE block

	//if it makes it this far without returning 0, it's a valid string!!
	return(1);
	

} //end of FUNCTION block

//translates sudokuRow (the string) into a c-string array called sudokuArray
void SudokuRowChecker :: loadArray()  {

	strcpy(sudokuArray , (sudokuRow.c_str()));

}

