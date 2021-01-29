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
3/02/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/



#include "assignment1.h"
void prompt_and_exit(int status) 
{
	printf("\n");
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
