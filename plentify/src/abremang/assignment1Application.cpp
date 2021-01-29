/* 

exampleApplication.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

The program reads an input file containing floating point values of the time, x and y coordinates of the ant at position.
Moreover, the first value in the input file represents the number of test cases.
Therefore, the program reads each line of code for it’s time stamp, x and y coordinates.
Also, the x and y coordinates read are truncated into decimal integers.
The program reviews the data read and removes repetitions and adds an identification number to the unrepeated locations writes in the output file.



Input
-----

First line of the input file contains a number which represents the amount of data input.
The rest of the data is made up of three set of float digits;
-1st column for the time
-2nd column for the x -coordinates
-3rd column for the y-coordinates

Moreover, each data file is separated by a time value by -1.00.



Output
------
The output file is made up of four columns;
- the first column contains unique identification numbers
- the second column contains the time in float type
- the third column contains the x coordinates as an integer
- the fourth column contains the y coordinates as an integer.


Sample Input
------------

2
0.100 0.000 1.000
1.200 0.000 1.000
-1.000 0.000 0.000
4.100 5.000 7.000
9.000 6.000 4.000
-1.000 0.000 0.000



Sample Output
-------------

abremang
1 0.100 0.000 1.000
--------------
1 4.100 5.000 7.000
2 9.000 6.000 4.000
--------------



Solution Strategy
-----------------
Below is an algorithm in the form of a pseudo code for the program;

Creating data structure
------------------------
Create an array of struct with;
Int time;
Int x_coordinates
Integer of y_coordinates
Integer of unique_identifier

reading files
---------------
Open input file and read from it 
Open output file and write to it 
Testcases = first line read from input file 
for (i =0; i< Testcases; i++)
{
Read(time, x and y coordinates from the lines of code)
While (t > 0)
{
Check for repetitions
----------------------
Loop through the number of elements in the array 
{
If(previous x_coordinates == current x_coordinates) and (previous y_coordinates == current y_coordinates)
{
Return a value of -1 
}
Else 
{
Return the length of the loop +1
}
}
If (number returned > 0)
{
Add to struct 
Time read
x_coordinates read
y_coordinates read 
the value returned as the unique identifier number.
}

Read a new line from the input file

}
When the while loop ends;
Print all the values in the array

}
Close both input and output files



Test Strategy
-------------

Various test cases used for the program where

- Different datasets with the same values 
- A dataset with a single set of value repeated through out 
- Unsorted time coordinates for test cases
- A test case with more initialized value of datasets than provided. For example if the first line of code states 4 test cases, but only two test cases provided.




File organization
-----------------

example.h                  interface file:      
contains the declarations required to use the functions that implement the solution to this problem
typically, these will include the definitions of the abstract data types used in the implementation

exampleImplementation.cpp  implementation file: 
contains the definitions of the functions that implement the algorithms used in the implementation

exampleApplication.cpp     application file:    
contains the code that instantiates the abstract data types and calls the associated functions
in order to effect the required functionality for this application


Author
------

Asantewaa Bremang
03/02/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

#include "assignment1.h"


/*
* File:   morseLED.c
* Author: freea
*
* Created on May 9, 2020, 11:38 PM
*/
#define STRING_LENGTH 1000

/*#include <xc.h>
#include "mc.h"*/
struct morsecode {
	char character;
	char *code;
};

void characterNmorseCodePair(struct morsecode arrayValue[])
{
	arrayValue[0].character ='a';
	arrayValue[0].code =".-";
	arrayValue[1].character ='b';
	arrayValue[1].code ="-...";
	arrayValue[2].character ='c';
	arrayValue[2].code ="-.-.";
	arrayValue[3].character ='d';
	arrayValue[3].code="-..";
	arrayValue[4].character ='e';
	arrayValue[4].code =".";
	arrayValue[5].character ='f';
	arrayValue[5].code ="..-.";
	arrayValue[6].character ='g';
	arrayValue[6].code ="--.";
	arrayValue[7].character ='h';
	arrayValue[7].code ="....";
	arrayValue[8].character ='i';
	arrayValue[8].code ="..";
	arrayValue[9].character ='j';
	arrayValue[9].code =".---";
	arrayValue[10].character ='k';
	arrayValue[10].code ="-.-";
	arrayValue[11].character ='l';
	arrayValue[11].code=".-..";
	arrayValue[12].character ='m';
	arrayValue[12].code ="--";
	arrayValue[13].character ='n';
	arrayValue[13].code ="-.";
	arrayValue[14].character ='o';
	arrayValue[14].code ="---";
	arrayValue[15].character ='p';
	arrayValue[15].code =".--.";
	arrayValue[16].character ='q';
	arrayValue[16].code ="--.-";
	arrayValue[17].character ='r';
	arrayValue[17].code =".-.";
	arrayValue[18].character ='s';
	arrayValue[18].code ="...";
	arrayValue[19].character ='t';
	arrayValue[19].code="-";
	arrayValue[20].character ='u';
	arrayValue[20].code ="..-";
	arrayValue[21].character ='v';
	arrayValue[21].code ="...-";
	arrayValue[22].character ='w';
	arrayValue[22].code =".--";
	arrayValue[23].character ='x';
	arrayValue[23].code ="-..-";
	arrayValue[24].character ='y';
	arrayValue[24].code ="-.--";
	arrayValue[25].character ='z';
	arrayValue[25].code ="--..";
	arrayValue[26].character ='1';
	arrayValue[26].code =".----";
	arrayValue[27].character ='2';
	arrayValue[27].code="..---";
	arrayValue[28].character ='3';
	arrayValue[28].code ="...--";
	arrayValue[29].character ='4';
	arrayValue[29].code ="....-";
	arrayValue[30].character ='5';
	arrayValue[30].code =".....";
	arrayValue[31].character ='6';
	arrayValue[31].code ="-....";
	arrayValue[32].character ='7';
	arrayValue[32].code ="--...";
	arrayValue[33].character ='8';
	arrayValue[33].code ="---..";
	arrayValue[34].character ='9';
	arrayValue[34].code ="----.";
	arrayValue[35].character ='0';
	arrayValue[35].code ="-----";
	arrayValue[36].character ='.';
	arrayValue[36].code =".-.-.-";
	arrayValue[37].character =',';
	arrayValue[37].code ="--..--";
	arrayValue[38].character =':';
	arrayValue[38].code ="..--..";
	arrayValue[39].character ='?';
	arrayValue[39].code ="..--..";
}

void ledflashingCode(char morseCode[])
{
	int k=0;
	printf("code length %d\n",strlen(morseCode));
	if (strlen(morseCode) > 0)
	{
		for(k =0; k<strlen(morseCode);k++)
		{
			if(morseCode[k]== '.')
			{
				printf("led on\n");
			}
			else if (morseCode[k]== '-')
			{
				printf("led off\n");
			}
			else if (morseCode[k] == ' ')
			{
				printf("blink twice\n");

			}


		}
	}
	else 
	{
		printf("light out\n");
	}
}


char* getMorseCode(struct morsecode arrayValue[], char stringVal[])
{
	int count = 0;
	char morseCode[STRING_LENGTH] ="";
	bool foundChar = false;
	printf("word length %d\n",strlen(stringVal));
	for (int j=0; j<strlen(stringVal);j++)
	{
		for(int i=0; i<39;i++)
		{
			if(tolower(stringVal[j])== arrayValue[i].character)
			{
				//printf("%s",arrayValue[i].code);
				strcat(morseCode,arrayValue[i].code);
				strcat(morseCode," ");
				foundChar = true;
				break;
			}
		}
		/*if (!foundChar)
		{
		morseCode =" ";
		}*/
		//printf("%s\n",arrayValue[i].code);
	}
	return morseCode;
}
struct morsecode charactersOfMorseCode[39];
void main(void) {
	//char value[STRING_LENGTH] = "abcdefghijklmnopqrstuvwxyz123456789,.;:?";
	char value[STRING_LENGTH] = "ABBA";
	characterNmorseCodePair(charactersOfMorseCode);
	printf("value length %d\n",strlen(value));
	printf("%s\n",getMorseCode(charactersOfMorseCode,value));
	ledflashingCode(getMorseCode(charactersOfMorseCode,value));

	prompt_and_exit(1) ;
}




