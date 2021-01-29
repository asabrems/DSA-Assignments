/* 

assignment5Application.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

The program seeks to plan a robot's path using Breadth-first search in an undirected and Unweighted graph. 
The robot's occupancy grid is read in as a matrix. The matrix has four main types of values, zero(0), one(1), two(2) and three(3),
where one represents an obstacle, two represents the start point, three represents the goal and zero represents a path a robot could navigate.
The robot is allowed to move forward, backward and sideways, that is; move from the cell
(i, j) to cells (i, j-1), (i, j+1), (i-1, j), or (i+1, j).
In the program, the limit for the matrix size is 100 by 100. Also, a robot's map has one starting point and one goal. 
Moreover, the robot map is converted to a graph where similar neighbouring occupancy cells are connected in the graph.
Therefore, for example, neighbours with similar values as 0 will be connected. 
After a graph has been developed, a breadth-first search is performed on the graph generated to find the shortest path.

Input
-----

The first line of the input file contains a number the number of scenarios of different robot occupancy map to be considered.
the lines after providing information for each specific dataset
each dataset begins with the two integers representing the rows and column of the map.
following this information is a matrix containing all, some or none of the values one(1), two(2) and three(3)
the number 1 represents an obstacle
the number 2 represents the start point 
the number 3 represents the goal point
each dataset is separated from each other with a line dimension for the row and column of the graph


Output
------
The first line of the output file contains the andrew id "abremang."
The output file contains the path of the robot from the start position to the goal position
the start position is represented by "@ "; the goal position is represented by "$ ", 
and the path of the robot is represented by "* ". 
Moreover, obstacles are represented by "# " and clear paths which were not considered by the robot are represented by " ".
Furthermore, each test case is introduced by "Scenario "number of test case" ".
A next line separates each test data in the output file.


Sample Input
------------

2
4 4
2 0 0 0 
0 1 1 0 
0 0 0 0 
0 0 0 3
10 10
0 0 0 0 0 0 0 0 0 0
0 2 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 1 1 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 3 0
0 0 0 0 0 0 0 0 0 0 


Sample Output
-------------

abremang
Scenario 1
@       
* # #   
*       
* * * $ 

Scenario 2
                    
  @                 
  *                 
  *   # # # # # #   
  *   # # # #       
  *   # # # #       
  * * * * # #       
  # # # *           
  # # # * * * * $ 



Solution Strategy
-----------------
Below is an algorithm in the form of a pseudo code for the program;

Open input file and read from it 
Open output file and write to it 

Testcases = first line read from input file 

for (i =0; i< Testcases; i++)
{
Read the x and y dimension of the graph
Map = read matrix from the input file

For (j=0; j<y; j++)
{
For (i=0; i<x; i++)
{
Obtain the start coordinates 
Obtain the goal coordinates
}
}

Convert the start and end values in the map to zeros

Create a graph with the root’s map
Perform a bfs on the graph
Find_path = find_path(graph)

If(there is a path)
{
Print the path
}

Else
{
Print there is no path
}

}

Close the input and output files 
}
}


Test Strategy
-------------

Various test cases used for the program where

- A dataset with all matrix values set to 1 
- A dataset with all matrix values set to 0
- A dataset with a 1 by 2 matrix, with only the start and the goal value
- A dataset with no values in the matrix, a 0 by 0 matrix
- A dataset with no path from start to go
- A dataset with no start cordinate
- A dataset with no goal cordinate

Order of complexity 
--------------------
The order of complexity of the program is  O(n^4).
The main functions in the project, that is;
the read function has an order of complexity of O(n^2),
the function reads obtains the start and goal coordinates has an order of complexity of O(n^2),
the function for map creation has order of complexity O(n^2),
the function for printing the graph has an order of complexity O(n^3),
therefore;
n(n^2+ n^2 + n^2+ 1+ n^3) =n^4


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
31/03/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

#include "assignment5.h"

/* 
Moreover most of the codes are modified version of David Vernon's wavefront path planner code.
Application file 

Wavefront path planner, Version 2

Course 04-630 Data Structures and Algorithms for Engineers, Assignment 5

Sample code to demonstrate how to read the input file

David Vernon
23 March 2020

*/
bool alternative_map_format = true; // flag to choose different map format; not relevant here

int main() {

	bool debug = false;
	FILE *fp_in, *fp_out;
	int i;

	graph g;
	bool directed = false;
	int robot_x, robot_y;
	int goal_x,  goal_y;
	int robot;
	int goal;
	int map_dimension_x, map_dimension_y;
	int scenario; 
	int number_of_scenarios;
	int map[MAX_N][MAX_M];
	int outputMap[MAX_N][MAX_M];
	int vertex[MAX_N*MAX_M];
	int length;
	int start;
	int end;
	bool path;
	int k,j,l;
	queue q;

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		getchar();
		exit(0);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		getchar();
		exit(0);
	}

	if (debug) printf("Wavefront Breadth First Search Path Planning\n");

	fprintf(fp_out, "abremang\n");

	scenario = 0;


	fscanf(fp_in, "%d",&number_of_scenarios);

	for (i=0; i<number_of_scenarios; i++) {
		path = false;
		robot_x=-1;
		robot_y=-1;
		goal_x=-1;
		goal_y =-1;
		init_queue(&q);
		end =0;
		start = 0;
		fprintf(fp_out, "Scenario %d\n",i+1);

		fscanf(fp_in, "%d %d",&map_dimension_x, &map_dimension_y); // read the dimensions of the map
		if(map_dimension_x <= 100 && map_dimension_y <= 100 )
		{
			read_map(fp_in, map, map_dimension_x, map_dimension_y);  // read the input file and initialize the map array

			for (j =0; j<map_dimension_x;j++)
			{
				for (l =0; l<map_dimension_y;l++)
				{
					if(map[j][l] ==3)
					{
						goal_x =j;
						goal_y =l;
						end = storageMappingValue(j, l,map_dimension_y);
					}
					else if(map[j][l] ==2)
					{
						robot_x =j;
						robot_y =l;
						start= storageMappingValue(j, l,map_dimension_y);
					}
				}
			}
			
			length = storageMapping(map,map_dimension_x,map_dimension_y,vertex,outputMap);
			
			printf("graph here\n");
			creategraph(&g, outputMap,vertex,map_dimension_x, map_dimension_y);
			//print_graph(&g);
			//if(start > 0)
			//{
				bfs(&g, start);
				path = find_path(&g, start, end,&q);
			//}
			if (path == false) 
			{
				fprintf(fp_out, "No path from (%d %d) to (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
				printf( "No path from (%d %d) to (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
				//print_path(fp_out, map, map_dimension_x,  map_dimension_y,  vertex, &q,   outputMap);
			}

				print_path(fp_out, map, map_dimension_x,  map_dimension_y,  vertex, &q,   outputMap);

		}
		else
		{
			fprintf(fp_out,"-------------------exceed array limit-------------------\n");
		}
		//read_graph(&g, false);
		/* get the robot and goal coordinates from the map, indicated by values 2 and 3. respectively. 
		HINT: reset the values to 0, i.e. an unoccupied cell, to allow the graph to be constructed correctly

		get_start_and_destination_coordinates(map, map_dimension_x, map_dimension_y, &robot_x, &robot_y, &goal_x, &goal_y); 
		*/

		if (debug) {
			printf("Scenario %d\n",i+1);
			printf("Map dimensions: %d %d\n", map_dimension_x, map_dimension_y);
			printf("Robot and goal positions: (%d %d), (%d %d)\n", robot_x, robot_y, goal_x, goal_y);
		}

		printf("----------------------------------\n");
		fprintf(fp_out,"\n");
	}

	fclose(fp_in);
	fclose(fp_out);

	//prompt_and_exit(1);
	// keep the terminal open until the user hits return
	if (debug) {
		printf("Press <return> to finish"); 
		getchar();
	}
}





