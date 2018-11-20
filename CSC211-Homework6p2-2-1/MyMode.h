#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//SIZE OF THE ARRAY
const int SIZE = 20;
//TO BE USED FOR RANDOM NUMBERS
const int RANGE = 10;

class MyMode
{
private:
	//VARIABLE DECLARATIONS
	int arr[SIZE];

	//GETS CALLED TO INITIALIZE THE ELEMENTS IN THE ARRAY
	void initArray(fstream&);
public:
	//CONSTRUCTOR
	MyMode();
	MyMode(fstream&);

	//DESTRUCTOR
	~MyMode();

	//DISPLAY THE VALUES IN THE ARRAY
	void printArray(fstream&) const;

	//LOOK FOR THE MODAL VALUE IN THE ARRAY
	const void lookForMode(fstream&);

	//A FUNCTION FOR CHECKING THE TEMP ARRAY IF A VALUE
	//HAS ALREADY BEEN COUNTED
	bool ifExists(const int*, int);

	//THIS FUNCTION WILL BE USED FOR COMPARING THE INDEX OF AN ELEMENT
	//TO THE REST OF THE ELEMENT IF IT'S GREATER OR EQUAL.
	//IF TRUE, WILL TAKE THE CURRENT BOOL VARIABLE VALUE AND MULTIPLY TO TRUE
	//ELSE, TAKE CURRENT BOOL VARIABLE VALUE AND MULTIPLY TO FALSE
	bool ifGreaterOrEqual(const int, const int, bool&);
};