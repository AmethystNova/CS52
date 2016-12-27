#include <iostream>
#include <string>
#include <cstring>
#include "sudokuRowChecker.h"
using namespace std;

int main() {

SudokuRowChecker checker;

//testing default constructor
checker.setData( "123456789" );

//this should be looking good! 
if (checker.isValid()) {
   cout << "looks good! CHECK" << endl;
} else {
   cout << "looks bad!" << endl;
}
/***********************************************************************************/
//empties it out.
checker.clear( );

//this should be looking bad! (non-unique integers and invalid input)
if (checker.isValid()) {
   cout << "looks good!" << endl;
} else {
   cout << "looks bad! CHECK" << endl;
}

/********************************************************************************/

checker.setStringData("12345678901");

//this should be bad... too long, repeated integers, invalid integer.
if (checker.isValid()) {
   cout << "looks good!" << endl;
} else {
   cout << "looks bad! CHECK" << endl;
}

/********************************************************************************/
checker.clear( );

//this should be bad... non-unique elements.
checker.setData( "123456799" );
if (checker.isValid()) {
   cout << "looks good!" << endl;
} else {
   cout << "looks bad! CHECK" << endl;
}

/*******************************************************************************/

//this should look good... setstringdata!
checker.clear();

checker.setStringData("123456789");

if (checker.isValid()) {
   cout << "looks good! CHECK" << endl;
} else {
   cout << "looks bad!" << endl;
}
/*******************************************************************************/

//this should look bad... too short.
checker.clear();

checker.setStringData("1289");

if (checker.isValid()) {
   cout << "looks good!" << endl;
} else {
   cout << "looks bad! CHECK" << endl;
}


return(0) ;


}