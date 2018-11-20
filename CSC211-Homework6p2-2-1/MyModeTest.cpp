#include "MyMode.h"

int main()
{
	try
	{
		//GENERATES RANDOM NUMBERS TO BE SAVED
		//IN THE TEXTFILE
		fstream outFile;
		outFile.open("RandomlyGeneratedNumbers.txt", ios::out);
		srand(time(NULL));
		for (size_t i = 0; i < SIZE; i++)
		{
			outFile << rand() % RANGE + 1 << endl;
		}
		outFile.close();
		//-----------------------------------------------------------
		//-----------------------------------------------------------

		//CREATES AN fstream OBJECT
		fstream inFile("RandomlyGeneratedNumbers.txt", ios::in);
		MyMode newMode(inFile); //pass the inFile object to the constructor

		//opens another text file to save the screen output
		outFile.open("ScreenOutput.txt",ios::out);
		newMode.printArray(outFile);
		outFile.close();
		outFile.open("ScreenOutput.txt", ios::app);
		newMode.lookForMode(outFile);
		outFile.close();
		cout << endl << endl;
	}
		
	catch (exception& e)
	{
		// DO NOTHING
	}

	system("pause");
	return 0;
}