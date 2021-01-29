/* 

exampleApplication.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.
The aim of the project is to find the maximum minimium path for passengers travelling from one city to another.
The programs allow find the route to take all tourists to the destination city in the
minimum number of trips. In the event that it is not possible to find a route that will allow the
tourists to be taken to the destination, the program should print an appropriate message.
When running the program, no user interaction should be required.



Input
-----

The input will contain one or more test cases. 
The first line of each test case will contain two integers: N (N ≤ 20) and R, representing the number of cities and the number of road
segments, respectively. Each of the next R lines will contain three integers (C1, C2, and P)
where C1 and C2 are the city numbers and P (P > 1) is the maximum number of passengers
that can be carried by the bus service between the two cities. City numbers are positive
integers ranging from 1 to N . The (R + 1) th line will contain three integers (S, D, and T)
representing, respectively, the starting city, the destination city, and the number of tourists to
be guided. The input will end with zero values for N and R. You can assume that all input
provided is valid and contains no errors.


Output
------
For each test case in the input, output:
1. the scenario number
2. the minimum number of trips required, followed by the number of tourists per trip
(taking as many tourists as possible on each trip except possibly the final trip)
3. the route to be taken
All three items are to printed on a separate line. Print a blank line after the output for each
test case


Sample Input
------------
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99
6 6
1 2 30
1 3 15
2 4 20
3 5 11
4 6 10
5 6 20
1 6 49
0 0


Sample Output
-------------
abremang
Scenario 1
Minimum Number of Trips = 5: 24 24 24 24 3 
Route = 1 2 4 7 

Scenario 2
Minimum Number of Trips = 5: 10 10 10 10 9 
Route = 1 3 5 6 



Solution Strategy
-----------------
Below is an algorithm in the form of a pseudo code for the program;

Open input file and read from it 
Open output file and write to it 
Read input file
while (cities !=0 && roads !=0)
{
	Read the edges to a map;
      Create a graph of with the map;
Read the start, end and number of passengers;
Read edges and store in a queue;
Sort the queue in ascending order;
While(connected component <=1) // the connected component traverse the graph with a bfs
{
Dequeue from priority queue;
Store the last edge dequeued;

}
Enqueue the last value dequeued;
Find path;
Find the number of passengers that can travel and the amount of trips needed.

}

Close both input and output files



Test Strategy
-------------

Various test cases used for the program where

- A dataset with the same number of weights for each road
- A dataset with number of passengers equal to the minimium weight
- A boundary testcase of 2 passengers
- A testcase with start being the maximum vertice and end being the least vertice
- A dataset with equal amount of roads as cities.



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

#include "assignment6.h"

int number_of_test_cases;
int i, counter;
int value;
bool pths;
int cities =0;
int roads =0;
float t, x, y;
int weight;
int start;
int end;
int tourists;
int temp_time;
int end_of_file;
bool directed = false;
int seats;
int minw =0;
int map[MAX_M][MAX_M];
graph g;
queue1 q;
struct ant_location_type location[max_input_to_array];

int main() {
	seats =0;
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
	int columns =3;
	fscanf(fp_in, "%d %d", &cities, &roads); 
	printf("cities , roads %d %d\n", cities, roads);

	counter =0;
	while (cities !=0 && roads !=0)
	{ vals vaq;
	init_queue1(&q);
	pths = false;
	counter = counter+1;
	fprintf(fp_out, "Scenario %d\n",+counter);
	initialize_graph(&g, directed);
	//initialize_search(&g);

	read_map(fp_in, map, roads, columns);
	fscanf(fp_in, "%d %d %d", &start, &end, &tourists); 


	//print_map(fp_out,   map, roads, columns);


	if (start == end)
	{
		fprintf(fp_out,"You are already visiting this city since you are at %d and want to go to %d\n",start, end);
		break;

	}
	else
	{
		creategraph(&g, map,roads, columns,cities, &q);

		printf("start:%d, end:%d, tourist:%d\n", start, end, tourists);
		print_queue1(&q);
		while(CC(&g) <= 1)
		{
			vaq = dequeue1(&q);
			find_vertex(&g, vaq.y_vals,vaq.x_val, directed);
			printf("cc values %d\n",vaq.y_vals);
			//print_graph(&g);
		}

		insert_edge(&g,vaq.x_val,vaq.y_vals, directed,vaq.weights);
		//add_parent(&g, vaq.y_vals,vaq.x_val,vaq.weights,directed);
		pths =find_path1(&g, start, end, q,fp_out);
		if (pths == TRUE)
		{
			printf("minimum wieght %d\n",output());
			int val =seats-1;
			int s =tourists ;
			int var =0;
			var =tourists/(seats-1);
			numOfTrips(tourists,output(), fp_out);
			print_path(fp_out);
			fprintf(fp_out,"\n");
		}

		else 
		{
			fprintf(fp_out,"there is not path\n");

		}
		printf("----------------------\n");
		fscanf(fp_in, "%d %d", &cities, &roads);

	}
	}

	fclose(fp_in);
	fclose(fp_out);
	prompt_and_exit(0);
}

