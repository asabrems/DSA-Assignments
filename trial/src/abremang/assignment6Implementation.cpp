/* 

exampleImplementation.cpp - implementation file for a program named example
============================================================================

This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

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



#include "assignment6.h"
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
void read_map(FILE *fp_in, int map[][MAX_M], int map_dimension_x, int map_dimension_y)
{

	int i, j;

	for (i=0; i<map_dimension_x; i++) {
		for (j=0; j<map_dimension_y; j++) {
			fscanf(fp_in, "%d", &(map[i][j])); // pass a pointer to the array element to be changed, i.e. the address of the element
			
		}
	}
}
void print_map(FILE *fp_out,  int map_value[][MAX_M], int map_dimension_x, int map_dimension_y)
{

	int i, j;

	for (i=0; i<map_dimension_x; i++) {
		for (j=0; j<map_dimension_y; j++) {
			// pass a pointer to the array element to be changed, i.e. the address of the element
			printf("%d ",(map_value[i][j]));
			fprintf(fp_out,"%d ",(map_value[i][j]));

		}
		printf("\n");
		fprintf(fp_out,"\n");
	}
}

void creategraph(graph *g, int map[][MAX_M],int map_dimension_x, int map_dimension_y, int vertices, queue1 *q1)
{
	int k,start, counter1;
	int i, j, x,y,counter, weight;
	bool directed = false;
	 vals arr;
	
	j=0;
	g->nvertices = vertices;

	for(i=0; i<map_dimension_x; i++)
	{
		/*for(j=0; j<map_dimension_y; j++)
		{*/
			if (g->nvertices != 0)
			{
				//x= storageMappingValue(i,j,map_dimension_y);
				x=map[i][j];
				y=map[i][j+1];
				weight =map[i][j+2];
				arr.weights = weight;
				arr.y_vals =y;
				arr.x_val =x;
				enqueue1(q1,arr);
				insert_edge(g, x, y, directed, weight);

			}
	}
	insertion_sort(q1);


}




