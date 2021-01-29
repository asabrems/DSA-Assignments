/* 

   example.h - interface file for a program named example
   ======================================================

   This program is for Assignment No.5, Course 04-630 Data Structures and Algorithms for Engineers. 

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
    03/02/2020


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

#include "graph.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define MAX_N 101
#define MAX_M 101
#define max_input_to_array 27001

struct ant_location_type
{
	float t_sorted;
	int x_sorted;
	int y_sorted;
	int id;
};


/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
int store_location(struct ant_location_type location[], float t, int x, int y, int i);
void read_map(FILE *fp_in, int map[][MAX_M], int map_dimension_x, int map_dimension_y);
void print_map(FILE *fp_out,  int map[][MAX_M], int map_dimension_x, int map_dimension_y);
int storageMapping(int map[][MAX_M], int map_dimension_x, int map_dimension_y, int vertex[],int outputMap[][MAX_M]);
void creategraph(graph *g, int map[][MAX_M], int vertex[],int map_dimension_x, int map_dimension_y);
void print_path(FILE *fp_out,  int map[][MAX_M], int map_dimension_x, int map_dimension_y, int vertex[], queue *q, int outputMap[][MAX_M]);
int storageMappingValue(int i, int j,int map_dimension_y);