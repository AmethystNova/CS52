#include <iostream>
#include <string>
#include "grader.h"
using namespace std;

const int SIZE=5;

int main () {
	
		
	Grader g;
	int d[5]= {99,70,85,93,84};
	int e[4]= {100,81,60,91};
	int f[3]={80,80,100};
	int h[1]={120};


	g.addScore( 75 );
	g.addScore( 82);
	g.addScores( d, 5 ); 


	cout << "Best Score = " << g.findBiggest( ) << endl;
/// should give value 99
	cout << "Worst Score = " << g.findSmallest( ) << endl;
/// should give value 70
	g.clear( );


	g.addScore( 50 );
	g.addScore( 74 );
	g.addScores( e, 4 ); 

cout << "Best Score = " << g.findBiggest( ) << endl;
/// should give value 100
cout << "Worst Score = " << g.findSmallest( ) << endl;
/// should give value 50

//testing "finding biggest" and "smallest" in an empty array:
	g.clear();
	g.findBiggest();
	g.findSmallest();
	g.addScore(98);
	//the biggest should be the smallest:
	cout << "BEST SCORE = " << g.findBiggest() << endl;
	cout << "WORST SCORE = " <<g.findSmallest() << endl << endl;

	//adding a set of scores
	g.addScores(f,3);
	//best should be 100; worst should be 80
	cout << "BEST SCORE = " << g.findBiggest() << endl;
	cout << "WORST SCORE = " <<g.findSmallest() << endl << endl;

	//adding an array with a single element:
	g.addScores(h,1);
	//best should be 120; worst should be 80
	cout << "BEST SCORE = " << g.findBiggest() << endl;
	cout << "WORST SCORE = " <<g.findSmallest() << endl << endl;


	return(0) ; 

}




