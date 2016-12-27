ROBLEM SET #8 : SUDOKU ROW CHECKER

NAME: Kimberly Hernandez

COURSE: CS52

DATE: 11/10/16

PURPOSE: String data in C++ can be stored using the STRING class or as a c-string (a char array with a NULLCHAR denoting the end of the array).
		Oftentimes, the abstracted STRING class is alot easier to work with. This program should highlight the differences and similarities between the two.
		The SudokuRowChecker class stores both a STRING and a c-string of data (the ints that compose them are equal), and checks whether they're valid
		rows in a sudoku game (ie unique integers [1,9]) by processing the strings.
    
INPUT: The user can choose to set the data as a STRING or as a c-string. 

OUTPUT: If invoked, the class has a member function that returns the boolean TRUE if the string is indeed a valid sudoku row.
