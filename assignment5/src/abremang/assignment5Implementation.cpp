/* 

exampleImplementation.cpp - implementation file for a program named example
============================================================================

This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

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



#include "assignment5.h"

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


int storageMapping(int map[][MAX_M], int map_dimension_x, int map_dimension_y, int vertex[],int outputMap[][MAX_M])
{
	int i, j, counter;
	for(i=0; i<map_dimension_x; i++)
	{
		for(j=0; j<map_dimension_y; j++)
		{
			vertex[(i*map_dimension_y) +j+1] = map[i][j];
			if ((map[i][j] == 2) || ( map[i][j] == 3))
			{
				outputMap[i][j] = 0;
			}
			else
			{
				outputMap[i][j] = vertex[(i*map_dimension_y) +j+1];
			}
		}

	}
	counter = map_dimension_x*map_dimension_y;
	return(counter);
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
int storageMappingValue(int i, int j,int map_dimension_y)
{	
	int value =0;
	value =(i*map_dimension_y) +j+1;

	return (value);
}


void creategraph(graph *g, int map[][MAX_M], int vertex[],int map_dimension_x, int map_dimension_y)
{
	int k,start, counter1;
	int i, j, x,y,counter;
	bool directed = false;
	initialize_graph(g, directed);

	g->nvertices = map_dimension_x*map_dimension_y;

	for(i=0; i<map_dimension_x; i++)
	{
		for(j=0; j<map_dimension_y; j++)
		{
			if (g->nvertices != 0)
			{
				x= storageMappingValue(i,j,map_dimension_y);
				if (map[i][j] == map[i][j+1])
				{
					y=storageMappingValue(i,j+1,map_dimension_y);
		
					if((j+1) < map_dimension_y)
					{
						insert_edge(g, x, y, directed, 0);
					}
				}
				if (map[i][j] == map[i+1][j])
				{
					y=storageMappingValue(i+1,j,map_dimension_y);
				
					if(y < g->nvertices)
					{
						insert_edge(g, x, y, directed, 0);
					}
				}

			}
		}
	}

}


void print_path(FILE *fp_out,  int map[][MAX_M], int map_dimension_x, int map_dimension_y, int vertex[], queue *q, int outputMap[][MAX_M])
{
	int i, j, position, value, check;
	for(i=0; i<map_dimension_x; i++)
	{
		for(j=0; j<map_dimension_y; j++)
		{
			if(map[i][j] == 2)
			{
				outputMap[i][j]= '@';
			}
			else if(map[i][j] == 3)
			{
				outputMap[i][j]= '$';
			}
			position =(i*map_dimension_y) +j+1;
			if ((q)->count > 0)
			{
				check =  dequeue(q);
				enqueue(q,check);
			}
				while ((q)->count > 0 && (check != value))
				{
					value = dequeue(q);
					if(value == position)
					{
						break;
					}
					else

					{

						enqueue(q,value);
					}

				}
				if(value == position)
				{
					 if (vertex[(i*map_dimension_y) +j+1] == 0)
					{
						outputMap[i][j]= '*';
					}

				}

				else
				{
					//enqueue(q,value);
					if (vertex[(i*map_dimension_y) +j+1] == 1)
					{
						outputMap[i][j]= '#';
					}
					else if (vertex[(i*map_dimension_y) +j+1] == 0)
					{
						outputMap[i][j]= ' ';
					}

				}
				
			fprintf(fp_out,"%c ",(outputMap[i][j]));
			printf("%c ",(outputMap[i][j]));
		}
		fprintf(fp_out,"\n");
		printf("\n");
	}
}
