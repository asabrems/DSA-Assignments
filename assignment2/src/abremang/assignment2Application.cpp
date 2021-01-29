/* 

exampleApplication.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

The program reads an input file containing floating point values of the time, x and y coordinates of the ant at position.
Moreover, the first value in the input file represents the number of test cases.
Therefore, the program reads each line of code for it’s time stamp, x and y coordinates.
Also, the x and y coordinates read are truncated into decimal integers and the three columns read are stored in a struct of an array.
A multikey insertion sort is used to sort the time and location of the ants coordinates stored in the struct of an array.
the readings are sorted in an assending order in respect to the x coordinates. moreover, the y coordinates with similar x cordinates are sorted 
in assending order. 
and finally time with similar x coordinates and y coordinates are sorted in ascending order.
moreover, the program accepts values that are less than 27000 and x and y coordinates values are with the range of -450<x, y< 450




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
the output file begins with the andrew id "abremang"
The output file is made up of three columns;
- the first column contains the sorted time value with respect to similar x and y cordinates of the ant's position
- the second column contains sorted x position of the ant cordinates 
- the third column contains the sorted y cordinate with respect to similar x cordinates
each test case ends with "-----------------", 17 dashes.

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
 0.100    0    1
 1.200    0    1
-----------------
 4.100    5    7
 9.000    6    4
-----------------




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
			Stored x, y and time value read in the array;
			Read a new line from the input file

		}
		Multikey sort (key = t)
	    Multikey sort (key = y)
	    Multikey sort (key = x)

Multikey sort
----------------------
			Read the key value passed into the function 
			If (key == time)
		{
			Perform insertion sort on the time slot in array;
		}
		Else
		{
			If (key == x coordinate)
			{
				Perform insertion sort on the x coordinate slot in array;
			}
			If (key == y coordinate)
			{
				Perform insertion sort on the y coordinate slot in array;
			}
--------------------------------------------------------
	When the while loop ends;

			Write all the values in the array to the output file

		}
		Close both input and output files

			)


			Insertion sort
			---------------
			For (for (i =0; i< elements_in_array; i++)
		    {
			j=i
				while((j is greater than the first value of index 0) && (current value read from array <  pervious value in array))
				{
					Perform a swap function.
				}
		   }



Test Strategy
-------------

Various test cases used for the program where

- Different datasets with the same values 
- A dataset with a single set of value repeated through out 
- An empty dataset
- A test case with the same x coordinates 
- A test case with the same y coordinates
- empty test case
- A dataset with less testcases than specified

Order of complexity
--------------------
The order of complexity is O(n^3).
The reason is that, the function begins with an initial for loop of order of complexity n, 
Within the for loop are various functions and implementations.
1.	 a while loop with an order of complexity O(n); the while loop reads inputs and stores in the array of structs
2.	Three insertion sorts with order of complexity O(n^2)
3.	A for loop which writes the sorted values from the array to the output file, it has a complexity of O(n).
Therefore n(n+ 3(n^2)+ n) = complexity of O(n^3)


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
17/02/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

#include "assignment2.h"

int number_of_test_cases;
int i, counter;
int value;
float t, x, y;
int temp_time;
int x1, y1;
int checker;


int main() {


	struct ant_location_type location[max_input_to_array];
	int storage[4];
	char input_string[STRING_LENGTH];
	char key[STRING_LENGTH];

	int increment;
	int maxvalue;
	int debug = TRUE;
	char message[MAX_MESSAGE_LENGTH];
	value = 0;
	temp_time =0;
	checker = 0;
	FILE *fp_in, *fp_out;
	//itu_morsecode_dictionary.txt"
	if ((fp_in = fopen("../data/input","r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}

	location[0].t_sorted = 0.0;
	location[0].x_sorted = 0;
	location[0].y_sorted = 0;
	/*fgets(input_string, STRING_LENGTH, fp_in);
	sscanf(input_string, " %s", key);
	printf("value ooo %s\n",key);*/

	fprintf(fp_out,"abremang\n");

	fscanf(fp_in, "%d", &number_of_test_cases); 
	counter = 0;

	for(i = 0; i < number_of_test_cases; i++)
	{		
		fscanf(fp_in, "%f %f %f", &t, &x, &y);


		while (! (t < 0))
		{
			x1 = (int)x;
			y1 = (int)y;

			location[counter].t_sorted = t;
			location[counter].x_sorted = x1;
			location[counter].y_sorted = y1;
			counter = counter + 1;


			fscanf(fp_in, "%f %f %f", &t, &x, &y);

		}
		insertion_sort(location,'t', counter);
		insertion_sort(location,'y', counter);
		insertion_sort(location,'x', counter);
		
		

		for(int i= 0; i<counter;i++)// prints out values stored in the array
		{
			fprintf(fp_out, "%6.3f %4d %4d\n", location[i].t_sorted,location[i].x_sorted , location[i].y_sorted);
			printf("%6.3f %4d %4d\n", location[i].t_sorted,location[i].x_sorted , location[i].y_sorted);
		}

		fprintf(fp_out,"-----------------\n");
		counter = 0;// refreshes the counter
	}

	fclose(fp_in);
	fclose(fp_out);
}

