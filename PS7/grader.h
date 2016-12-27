#ifndef GRADER
#define GRADER
#include <iostream>
#include <string>
using namespace std;


class Grader {

public:
	//default constructor:
	Grader( );

	//Returns index of nearest empty element. Also doubles as counter of values.
	int emptyIndex();

	//adds a single score
	void addScore( int score );
	//adds a set of scores
	void addScores( int scores[], int size );
    
	//empties out the array of values
	void clear(); 


	int findBiggest( ) const;
	int findSmallest( ) const;
	
private: 

	static const int MAXSIZE=200;
	int my_Values[ MAXSIZE ];
	int my_valuesSeenSoFar;

} ; //end of class declaration


#endif


