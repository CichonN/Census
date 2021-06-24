// ------------------------------------------------------------------------------------------
// Name: Neina Cichon
// Abstract: Census
// Date: 2020-12-08
// ------------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable : 4996)


// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// User Defined Types (UDTs)
// --------------------------------------------------------------------------------
typedef struct
{
	int month;
	int day;
	int year;
}Date;


// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
int getState(char* strState[]);
void getCounty(char* strState[], char* strCounty[], int intState);
void getRace(char* strRace);
int getHouseholdSize();
int getIncome();
void PrintString(char strBuffer[]);
void CopyString(char strDestination[], char strSource[]);
void empty_stdin(void);
int AnotherTrans();


// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
int main()
{
	FILE* fpCensus;
	fpCensus = fopen("c:\\temp\\Census.txt", "a");
	int intIndex;
	Date date = { 0 };
	char* strDate[100];
	char* strState[100];
	char* strCounty[100];
	char* strRace[100];
	char* strData[6];
	int intState = 0;
	int intCounty = 0;
	int intRace = 0;
	int intHouseholdCount = 0;
	int intResponse = 0;
	float sngIncome = 0.0;
	const int Max_length = 32;

	do
	{
		//Get Date
		do
		{
			printf("Enter Date of Survey (MM/DD/YYYY): ");
			scanf("%d/%d/%d", &date.month, &date.day, &date.year);
			empty_stdin();
		} while (validateDate(&date.month, &date.day, &date.year) == 0);

		//Get State
		intState = getState(strState);

		//Get County
		getCounty(strState, strCounty, intState);

		//Get Race
		getRace(strRace);

		//Get Size of Household
		intHouseholdCount = getHouseholdSize();

		//Get income of household
		sngIncome = getIncome();

		//Print results to file
		fprintf(fpCensus, "%d/%d/%d,%s,%s,%s,%d,%f\n", date.month, date.day, date.year, strState, strCounty, strRace, intHouseholdCount, sngIncome);
		
		//Ask user if they want to enter another transaction
		intResponse = AnotherTrans();

	} while (intResponse == 1);

	//Close file
	fclose(fpCensus);

	system("pause");

}


// --------------------------------------------------------------------------------
// Name: getState
// Abstract: Get State from User
// --------------------------------------------------------------------------------
int getState(char* strState[])
{
	int intState = 0;

	//Get State
	do {
		printf("Enter State (Enter 1 for Ohio or 2 Kentucky): ");
		scanf("%d", &intState);
		empty_stdin();
	} while (intState < 1 || intState > 2);

	return intState;
}



// --------------------------------------------------------------------------------
// Name: getCounty
// Abstract: Get County from User
// --------------------------------------------------------------------------------
void getCounty(char* strState[], char* strCounty[], int intState)
{
	int intCounty = 0;

	//Get County
	if (intState == 1)
	{
		CopyString(strState, "Ohio");

		do {
			printf("Enter County (Enter 1 for Hamilton or 2 for Butler): ");
			scanf("%d", &intCounty);
			empty_stdin();
		} while (intCounty < 1 || intCounty > 2);

		if (intCounty == 1)
		{
			CopyString(strCounty, "Hamilton");
		}
		else
		{
			CopyString(strCounty, "Butler");
		}
	}
	else
	{
		CopyString(strState, "Kentucky");

		do {
			printf("Enter County (Enter 1 for Boone or 2 for Kenton): ");
			scanf("%d", &intCounty);
			empty_stdin();
		} while (intCounty < 1 || intCounty > 2);


		if (intCounty == 1)
		{
			CopyString(strCounty, "Boone");
		}
		else
		{
			CopyString(strCounty, "Kenton");
		}
	}

}


// --------------------------------------------------------------------------------
// Name: getRace
// Abstract: Get Race from User
// --------------------------------------------------------------------------------
void getRace(char* strRace)
{
	int intRace = 0;

	do
	{
		printf("Enter Race of Head of Household");
		printf("\n\t*Enter 1 for Caucasian");
		printf("\n\t*Enter 2 for African American");
		printf("\n\t*Enter 3 for Hispanic");
		printf("\n\t*Enter 4 for Asian");
		printf("\n\t*Enter 5 for Other\n");
		scanf("%d", &intRace);
		empty_stdin();
	} while (intRace < 1 || intRace > 5);

	if (intRace == 1)
	{
		CopyString(strRace, "Caucasian");
	}
	else if (intRace == 2)
	{
		CopyString(strRace, "African American");
	}
	else if (intRace == 3)
	{
		CopyString(strRace, "Hispanic");
	}
	else if (intRace == 4)
	{
		CopyString(strRace, "Asian");
	}
	else
	{
		CopyString(strRace, "Other");
	}
}


// --------------------------------------------------------------------------------
// Name: getHouseholdSize
// Abstract: Get Size of household from user
// --------------------------------------------------------------------------------
int getHouseholdSize()
{
	int intHouseholdCount = 0;

	//Get Size of Household
	do
	{
		printf("Enter number of people in household: ");
		scanf("%d", &intHouseholdCount);
		empty_stdin();
	} while (intHouseholdCount <= 0);

	return intHouseholdCount;
}


// --------------------------------------------------------------------------------
// Name: getIncome
// Abstract: Get Income of household from user
// --------------------------------------------------------------------------------
int getIncome()
{
	float sngIncome = 0;
	//Get income of Household
	do
	{
		printf("Enter Household Income: ");
		scanf("%f", &sngIncome);
		empty_stdin();
	} while (sngIncome <= 0);

	return sngIncome;
}


// --------------------------------------------------------------------------------
// Name: validateDate
// Abstract: Validate that date is valid
// --------------------------------------------------------------------------------
int validateDate(Date* date)
{
	if (date->month < 1 || date->month > 12 || date->month == NULL)
	{
		return 0;
	}
	else if (date->day < 1 || date->day > 31 || date->day == NULL)
	{
		return 0;
	}
	else if (date->year < 2000 || date->year > 3000 || date->year == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


// --------------------------------------------------------------------------------
// Name: PrintLength
// Abstract: Print a String
// --------------------------------------------------------------------------------
void PrintString(char strBuffer[])
{
	int intIndex = 0;

	while (strBuffer[intIndex] != 0)
	{
		printf("%c", strBuffer[intIndex]);
		intIndex += 1;
	}

}


// --------------------------------------------------------------------------------
// Name: CopyString
// Abstract: Copy Source String to Destination String Variable
// --------------------------------------------------------------------------------
void CopyString(char strDestination[], char strSource[])
{
	int intIndex = 0;

	while (strSource[intIndex] != 0)
	{
		strDestination[intIndex] = strSource[intIndex];
		intIndex += 1;
	}
	//terminate
	strDestination[intIndex] = 0;
}


// --------------------------------------------------------------------------------
// Name: empty_stdin
// Abstract: emptys buffer
// --------------------------------------------------------------------------------

void empty_stdin(void) {
	int unwantedCharacter = getchar();

	while (unwantedCharacter != '\n' && unwantedCharacter != EOF)
		unwantedCharacter = getchar();
}


// --------------------------------------------------------------------------------
// Name: AnotherTrans
// Abstract: Asks user if they want another transaction
// --------------------------------------------------------------------------------

	int AnotherTrans() 
	{
		int intResponse = 0;
		char chrResponse = 'Y';

		do {
			printf("Would you like to enter another household? (Y or N) ");
			scanf("%c", &chrResponse);
			empty_stdin();

		} while (chrResponse != 'Y' && chrResponse != 'y' && chrResponse != 'n' && chrResponse != 'N' );

		if (chrResponse == 'y' || chrResponse == 'Y')
		{
			intResponse = 1;
			
		}
		else
		{
			intResponse = 0;
		}
		return intResponse;
	}
