#include "MyMode.h"


MyMode::MyMode()
{
	//CONSTRUCTOR

	//FUNCTION CALL TO POPULATE THE ELEMENTS
	//IN THE ARRAY
	initArray();
}

MyMode::~MyMode()
{
	//DESTRUCTOR
}

void MyMode::initArray()
{
	//GENERATES RANDOM NUMBERS TO BE ASSIGNED
	//TO EACH ELEMENT IN THE ARRAY
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; i++)
	{
		*(arr + i) = rand() % RANGE + 1;
	}
}

void MyMode::printArray() const
{
	//THIS FUNCTION PRINTS ALL VALUES IN THE ARRAY
	cout << "The randomly generated array of integers are: " << endl << endl;
	cout << "[ ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(arr + i);

		if (i < SIZE && i != SIZE - 1)
		{
			cout << ", ";
		}
	}
	cout << " ]";
	cout << endl << endl;
}

const void MyMode::lookForMode()
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

			if (*(tempArr + i) > 1)
			{
				cout << " times" << endl;
			}
			else
			{
				cout << " time " << endl;
			}
		}
	}
	//////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////
	//SET MODE(S)
	cout << endl << "The mode(s) is/are: " << endl;
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