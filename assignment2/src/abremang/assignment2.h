/* 

   example.h - interface file for a program named example
   ======================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - exampleApplication.cpp - for details of the functionality of this program

      
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

   David Vernon, Carnegie Mellon University Africa
   05/01/2019
   Editted by : Asantewaa Bremang 
    17/02/2020


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define max_input_to_array 27001
#define STRING_LENGTH 1000


struct ant_location_type
{
	float t_sorted;
	int x_sorted;
	int y_sorted;

};
//struct ant_location_type temp; 


/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
int store_location(struct ant_location_type location[], float t, int x, int y, int i);
void insertion_sort(struct ant_location_type a[],char value , int increment);
void search_location2(struct ant_location_type location[],int x, int y,int range[], int increment, int num_of_elements_array);