#ifndef SUDOKUROWCHECKER
#define SUDOKUROWCHECKER
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class SudokuRowChecker {

public:
//default constructor. String AND array are initialized to full 0's.
SudokuRowChecker( );

//intakes a char* (to an array?). set data via user defined char array
void setData( char * s ) ;

//intake string of string type. straightforward modification of attribute.
void setStringData( std::string s );

//empty out array (set it to full 0's
void clear(); 

//"meat" of the program. Checks for uniqueness within string. (within single digit bound (1-9))
bool isValid( ) const;



private:
//ATTRIBUTES:
std::string sudokuRow;
char sudokuArray[10]; //9 for actual char values, 1 for NULLCHAR

//HELPER MEMBER FUNCTIONS:
//this copies the string data into a c-string style array.
void  loadArray() ;


} ; //END CLASS DECLARATION





#endif