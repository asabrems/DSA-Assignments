/* 

exampleImplementation.cpp - implementation file for a program named example
============================================================================

This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - assignment1Application.cpp - for details of the functionality of this program


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


Authors
------

David Vernon, Carnegie Mellon University Africa
05/01/2019

Editted by :  Asantewaa Bremang
17/02/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/



#include "assignment2.h"
void prompt_and_exit(int status) 
{
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[])
{

	fprintf(fp,"The message is: %s\n", message);
}

int store_location(struct ant_location_type location[], float t, int x, int y, int num_of_elements_array)
{
	int id_number;
	int a;

	id_number = 0;

	for (a = 0; a <= num_of_elements_array; a++)
	{ 
		if(((location[a].x_sorted) == x) && (location[a].y_sorted == y) ) //compare location for any similarities
		{			
			id_number = -1;
			break; // breaks out of loop anytime a match is found
		}

		id_number = num_of_elements_array+1;//increment unique identifier
	}

	return(id_number);

}



void insertion_sort(struct ant_location_type a[],char value  , int elements_in_array)
{
	int i,j;
	struct ant_location_type temp;
	float prior_value = 0;
	float current_value = 0;
	int temp_value;
	current_value = 0;
	current_value =0;

	for (i=1; i< elements_in_array; i++)
	{
		j=i;
		if (value == 't')// the if statements determine the key being sorted
		{
			current_value =a[j].t_sorted; 
			prior_value =a[j-1].t_sorted; 
		}
		else 
		{
			if (value == 'x')
			{
				current_value =(float)a[j].x_sorted; 
				prior_value =(float)a[j-1].x_sorted; 
			}
			if (value == 'y')
			{
				current_value =(float)a[j].y_sorted; 
				prior_value =(float)a[j-1].y_sorted; 
			}
		}
		while ((j>0) && (current_value  < prior_value) )
		{

			temp = a[j-1]; // swap
			a[j-1] = a[j];
			a[j] = temp;
			j = j-1;
			if (value == 'x') // the if statement in the while loop updates the current and prior values based on the key being sorted
			{
				current_value =(float)a[j].x_sorted; 
				prior_value =(float)a[j-1].x_sorted; 
			}
			if (value == 'y')
			{
				current_value =(float)a[j].y_sorted; 
				prior_value =(float)a[j-1].y_sorted; 
			}
			if (value == 't')
			{
				current_value =a[j].t_sorted; 
				prior_value =a[j-1].t_sorted; 

			}
		}
	}
}
