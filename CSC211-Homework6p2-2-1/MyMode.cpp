#include "MyMode.h"


MyMode::MyMode()
{
	//CONSTRUCTOR
}

MyMode::MyMode(fstream& inFile)
{
	//CONSTRUCTOR
	initArray(inFile);
}

MyMode::~MyMode()
{
	//DESTRUCTOR
}

void MyMode::initArray(fstream& inFile)
{
		string _input;
		//use stringstream to 
		//convert string to int easily
		stringstream in;	
		int input = 0, _i = 0;

		if (!inFile)
		{
			cout << "Error Opening File" << endl;
			exit(1);
		}

		while (!inFile.eof())
		{
			getline(inFile, _input, '\n');
			in << _input;
			in >> input;
			*(arr + _i) = input;
			in.str("");	//empty stringstream
			in.clear(); //clear stringstream to accept new value
			_i++;
		}
			
		inFile.close();
}

const char * c1 = "The randomly generated array of integers are: \n\n";
const char * c2 = "[ ";
const char * c3 = ", ";
const char * c4 = " ]\n\n";

void MyMode::printArray(fstream& outFile) const
{
	//THIS FUNCTION PRINTS ALL VALUES IN THE ARRAY
	cout << c1;	outFile << c1;
	cout << c2; outFile << c2;

	for (int i = 0; i < SIZE; i++)
	{
		cout << *(arr + i); outFile << *(arr + i);
		
		if (i < SIZE && i != SIZE - 1)
		{
			cout << c3; outFile << c3;
		}
	}
	cout << c4; outFile << c4;
}

const void MyMode::lookForMode(fstream& outFile)
{
	//THIS FUNCTION WILL LOOK FOR MODE IN THE ARRAY

	int tempArr[RANGE] = { 0 };	//THIS WILL SERVE AS A CONTAINER 
								//FOR THE COUNTER
	int counter = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (*(arr + i) == *(arr + j))
			{
				counter++;
			}
		}
		if (!ifExists(tempArr, *(arr + i) - 1))
		{
			*(tempArr + (*(arr + i) - 1)) = counter;
		}
		counter = 0;
	}

	//////////////////////////////////////////////////////////////
	//DISPLAY THE OCCURENCE OF EACH GENERATED VALUE IN THE ARRAY
	for (int i = 0; i < RANGE; i++)
	{
		if (*(tempArr + i) > 0)
		{
			cout << i + 1 << " occured " << *(tempArr + i);
			outFile << i + 1 << " occured " << *(tempArr + i);

			if (*(tempArr + i) > 1)
			{
				cout << " times" << endl;
				outFile << " times" << endl;
			}
			else
			{
				cout << " time " << endl;
				outFile << " time " << endl;
			}
		}
	}
	//////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////
	//SET MODE(S)
	cout << endl << "The mode(s) is/are: " << endl;
	outFile << endl << "The mode(s) is/are: " << endl;
	bool greaterOrEqual;
	for (int i = 0; i < RANGE; i++)
	{
		greaterOrEqual = true;

		for (int j = 0; j < RANGE; j++)
		{
			ifGreaterOrEqual(*(tempArr + i), *(tempArr + j), greaterOrEqual);
		}

		if (!greaterOrEqual)
		{
			*(tempArr + i) = 0;	//SET TO ZERO IF IT'S NOT A MODE
		}

		if (*(tempArr + i) > 1) //WILL ONLY DISPLAY OCCURENCE GREATER THAN 1
		{
			cout << i + 1 << "    ";
			outFile << i + 1 << "    ";
		}
	}
	////////////////////////////////////////////////////////////////
}

bool MyMode::ifGreaterOrEqual(const int a, const int b, bool &greaterOrEqual)
{
	//THIS FUNCTION WILL BE USED TO DETERMINE THE MODE(S)
	//IT HAS 3 ARGUMENTS, BOTH INTS WILL BE COMPARED, THEN
	//SETS THE BOOL VARIABLE TO 'MULTIPLY EQUALS' DEPENDING
	//RESULT OF THE CONDITION. THEN IT WILL RETURN THAT BOOL
	//VARIABLE
	if (a >= b)
	{
		greaterOrEqual *= true;
	}
	else
	{
		greaterOrEqual *= false;
	}

	return greaterOrEqual;
}

bool MyMode::ifExists(const int *tempArr, int val)
{
	//THIS FUNCTION WILL RETURN TRUE IF THE NUMBER HAS ALREADY BEEN COUNTED
	//OR FALSE OTHERWISE
	bool result = false;

	if (*(tempArr + val) <= 0)
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
}