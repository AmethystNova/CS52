
#include <iostream>
#include <string>
#include "grader.h"
using namespace std;


//The default constructor fills the freshly spawned array of MAXSIZE with negative flags, and initializes the "values seen so 
//far " counter to ZERO. (by invoking a function that counts the non-negative elements)
Grader :: Grader() {
	int i(0) ;

	for (i=0 ; i < MAXSIZE ; i++ ) {
		my_Values[i] = -1 ;
	}
	my_valuesSeenSoFar = emptyIndex();
}


//this returns the index of the "nearest" empty element. It also doubles as a counter.
int Grader :: emptyIndex() {


	int i(0); 

		while (my_Values[i] > 0 ) {
		i++;
	}
		return(i);
} 


//Appends a single element to the array.
void Grader :: addScore( int score ) { 

	//my values seen so far will hold the index of the next empty element.
	my_valuesSeenSoFar = emptyIndex() ; 
	//fill that empty index with the given score.
	my_Values[my_valuesSeenSoFar] = score;

	//since this function only allows a single value, we can use our unary operator:
	my_valuesSeenSoFar++;
} 


//Copies the elements of a user specified array (passed as arg) into my_Values[]. 
void Grader :: addScores( int scores[], int size ) {

	int i(0); //index for my_Values[]
	int n(0); //index for scores[]

	i = emptyIndex() ; 

	//copy the elements of the given array into my scores array: 
	n=0;
	for (n=0 ; n < size ; n++ ){

		my_Values[i] = scores[n] ; 
		i++;

	}

	//updates the counter:
	my_valuesSeenSoFar = emptyIndex();

}

//iterates through array while values are non-negative ("empty" elements) and resets them
//to the default flag of -1. In simpler terms, EMPTIES OUT THE ARRAY AND RESETS THE COUNTER.
void Grader :: clear() {

	int i(0);

	while (my_Values[i] > 0 ) {
		//set them to default negative flag
		my_Values[i] = -1 ;
		i++;
	}
	//update the counter. Should be zero.
	my_valuesSeenSoFar = emptyIndex();
}


int Grader :: findBiggest( ) const {

	int big(0), size(0), i(0);

	size = my_valuesSeenSoFar;


	if (size == 0 ) {
		cout << "No scores have been specified!" << endl;
	}
	else {

	//set big to be the first element of the array of values.
	big = my_Values[0];

	//siphon through every value, setting the relatively largest as the LARGEST.
	for (i = 0 ; i < size ; i++ )  {


		if ( big < my_Values[i] ) {
			big = my_Values[i] ;
		} //end of if
	} //end of for
	} //end of safeguard ELSE
	 
	 return (big) ;
}

//siphons through entire loaded portion of array and returns the smallest value
int Grader :: findSmallest( ) const {

	int small(0), size(0), i(0) ;

	size = my_valuesSeenSoFar ; 
	
	if (size == 0 ) {
		cout << "No scores have been specified!" << endl;
	}
	else

		small = my_Values[0];
	{
		for (i = 0 ; i < size ; i++ )  {


			if ( small > my_Values[i] ) {
				small = my_Values[i] ;
			}//end of internal conditional branch
		} //end of for loop
	}//end of safeguard ELSE

	return(small) ;


}




