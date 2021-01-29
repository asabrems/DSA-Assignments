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

int number_of_test_cases;
int i, counter;
int value;
float t, x, y;
int temp_time;

struct ant_location_type location[max_input_to_array];

int main() {

	int debug = TRUE;
	char message[MAX_MESSAGE_LENGTH];
	value = 0;
	temp_time =0;
	FILE *fp_in, *fp_out;

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}



	fprintf(fp_out,"abremang\n");

	fscanf(fp_in, "%d", &number_of_test_cases); 
	counter = 0;
	for(i = 0; i < number_of_test_cases; i++)
	{
		for(int a =0; a<27001; a++) // fill array with range of values are likely not to be part of the dataset
		{
			location[a].t_sorted = 0.0;
			location[a].x_sorted = 453;
			location[a].y_sorted = 478;
			location[a].id = 0;

		}
		fscanf(fp_in, "%f %f %f", &t, &x, &y);

		while (! (t < 0))
		{
			value = store_location(location, t, (int)x, (int)y, counter);//checks if x and y coordinates exists; also provides unique id

			if (value != -1)// stores values in the array
			{
				location[counter].t_sorted = t;
				location[counter].x_sorted = x;
				location[counter].y_sorted = y;
				location[counter].id = value;
				counter = counter + 1;
			}

			fscanf(fp_in, "%f %f %f", &t, &x, &y);

		}
		for(int i= 0; i<counter;i++)// prints out values stored in the array
		{
			fprintf(fp_out,"%3d %6.3f %4d %4d\n", location[i].id,location[i].t_sorted,location[i].x_sorted , location[i].y_sorted);
		}

		fprintf(fp_out,"--------------\n");
		counter =0;// refreshes the counter
	}

	fclose(fp_in);
	fclose(fp_out);
	prompt_and_exit(0);
}

