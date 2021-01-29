/* 

travellingSalesmanApplication.cpp - application file for the solution of the travelling saleman problem by exhaustive search using backtracking

04-630 Data Structures and Algorithms for Engineers Assignment No. 7

****************************************************************************************************************
*** This program only provides functionality for reading the test input and calling the generic backtrack    ***
*** function to print the permutations.                                                                      ***
***                                                                                                          ***
*** It must be extended to complete the assignment.                                                          ***
***                                                                                                          ***
*** The program prints the input to the terminal to verify that it has been read correctly.                  ***
***                                                                                                          ***
*** Since there are n! permutations for n destinations, printing the permutations can be distracting,        ***
*** although worth doing at least once to verify that permutations are being computed correctly.             ***
*** If you do want the n! permutations printed to the terminal, set the print_permuations flag to true       ***
*** in the process_solution() function. This function is located in the implementation file.                 ***
****************************************************************************************************************

OptiPizza – a new pizza restaurant – wants to minimize its delivery costs while not compromising on delivery times 
by delivering pizzas in batches to a small number of customers. To do this, they need to know the best route linking 
their pizza restaurant and the customers for each delivery run.  Given the distance between each customer drop-off point 
and the distance from the restaurant to each customer drop-off point, this application produces an optimal route for OptiPizza, 
i.e. the sequence in which a delivery moto should call to the customers after leaving the restaurant, returning to the restaurant 
once all pizzas have been delivered. The delivery moto calls to each customer location only once.

Input data for several test cases is provided in an input file: input.txt
Output for each test case is written to an output file: output.txt


Input
-----

- The first line of the input file consists of an integer number k specifying the number of test cases in the file.  
- This is followed by the data specifying each test case, beginning on the next line.  
- There are no blank lines in the input file.
- Each test case begins with a line containing an integer number n giving the number of pizza drop-offs locations. 
- This is followed by n+1 lines containing 

-- the n locations (i.e. the names and addresses) of each customer 
-- followed by the location of the restaurant. 
-- It is assumed that n < 10 and that each address is on a separate line.  

- This is followed by n+1 lines each containing n+1 integers specifying the distances between each location (including itself).  
- The jth number on line i gives the distance from location i to location j. 
- The j+1st number on line i gives the distance from customer i to the restaurant.  
- Note that the distance from location i to location j may not be the same as the distance from location j to location i 
since you may not be able to take the same path (we assume the delivery drivers obey the law and don’t drive the wrong way 
on a one-way street).  
- Line n+1 gives the distance of the restaurant to each customer location.


Output
------

- The first line of the output file contain the author's Andrew Id.

- For each test case in the input

-- The test case number is printed on a separate line
-- The total distance that needs to be travelled is printed on the next line
-- This is followed the sequence of customers that the delivery moto should use to minimize distance, 
starting at the restaurant and returning to the restaurant.

Each customer name and address is printed on a separate line

- If there is more than one tour (i.e. route from the restaurant to all delivery locations and back to the shop) 
that gives the same minimum distance, it prints the first one found.


Sample Input
------------
1
4
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Delete Street.
OptiPizza, #1 Mozzarella Road. 
0   3  10  5 12 
3   0  10  8  6 
10 11   0  3  6 
5   8   4  0  6 
12  6   9  7  0 


Sample Output
-------------
dvernon
1
24
OptiPizza, #1 Mozzarella Road. 
Mr. Someothername, #2 Someother Street.
Mr. Somename, #1 Some Street.
Ms. Ctrlaltname, #4 Delete Street.
Ms. Altname, #3 Alt Street.
OptiPizza, #1 Mozzarella Road. 

Outline Solution Strategy
-------------------------
The solution uses combinatorial search with backtracking and pruning. 
Hence we seek the permutation of the locations that provides the minimum length tour.
Instead of enumerating permutations of the location names and addresses 
we associate an integer key with each location and form permutations of these keys.

Solution Strategy(Pruning implementation is in the backtracking function)
-----------------
Below is an algorithm in the form of a pseudo code for the program;

Open input file and read from it 
Open output file and write to it 
Read input file
testcase = number of testcases
for(i=0; i<testcase;i++)
{
read addresses from the input file
store them in an struct of arrays
read distances and store in a 2D matrix
backtrack(an array a,k value,distance matrix, number of houses to visit)

printOut Minimum path

}

Close both input and output files

backtracking with Prunning
-----------------------------

backtrack(an array a,k value,distance matrix, number of houses to visit)
{

if (it is a solution)
{
distanceSum = distanceSum +(distance from final destination to pizza house)

if (minidistance< distanceSum)
{
minidistance = distanceSum
process_solution();
}
}

else
{
k=k+1
construct_candidates();
for(t=0;t<numberOfCand;t++)
{
add candidate to array of a[]

distanceSum = distance from pizza to start address

create a for loop to add all distances traversed to distance sum

//prunning starts here
if(distanceSum< minidistance)
{
call backtrack();
}
}
}
}

Test Strategy
----------------------
various testcases were developed to ensure an adequate functionality of the project
- A testcase with one destination 
- a testcase with 0 minimum distance
- a testcase with the same minimum distance
- a testcase with 9 delivery points
- a testcase with the minimum path as the last permutation
- a testcase with the minimum path as the first permutation
- a testcase with no deliveries

David Vernon
15 April 2020
edited by Asantewaa Bremang
29th April 2020
*/

#include "travellingSalesman.h"

int main() {

	struct record_type record[NUMBER_OF_STOPS];
	int distancesum =0;
	int i, j, k;                                      // general purpose counters
	int n; 
	int scenario=0;// number of customer drop-off locations
	int number_of_test_cases;                         //
	char stop_name[STRING_SIZE];                      // general purpose string
	int distances[NUMBER_OF_STOPS][NUMBER_OF_STOPS];  // distances between shop i (row) and shop j (column)
	int a[NMAX+1];                                    // permutation of locations
	int d[NMAX+1];
	int debug = TRUE;                                 // flag: if TRUE print information to assist with debugging
	int path[NMAX+1];
	FILE *fp_in, *fp_out;                             // input and output file pointers
	// initialize an array; this will store the optimal part, then in value from the array will be the ith value of record[i]

	/* open input and output files */

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		exit(0);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		exit(0);
	}
	scenario = 0;
	/* read the number of test cases */
	fprintf(fp_out,"abremang (pruning)\n");
	fscanf(fp_in, "%d", &number_of_test_cases);
	fgetc(fp_in); // move past end of line for subsequent fgets; fgets fails unless we do this

	if (debug) printf ("%d\n", number_of_test_cases);


	/* main processing loop, one iteration for each test case */

	for (k=0; k<number_of_test_cases; k++) {
		//setValue(1000);
		//printf("optimal distance %d\n",value());
		/* read the data for each test case  */
		/* --------------------------------  */

		/* number of customer drop-off locations */

		fscanf(fp_in, "%d", &n);
		fgetc(fp_in);  // move past end of line for subsequent fgets

		if (debug) printf ("%d\n",n);

		/* get the location names and the restaurant name */

		for (i = 0; i < n+1; i++) {

			fgets(stop_name, STRING_SIZE, fp_in);
			remove_new_line(stop_name);

			record[i].key = i+1;
			strcpy(record[i].string,stop_name);

			if (debug) printf ("%s\n",record[i].string);
		}

		/* get the matrix of distances */

		for (i = 0; i < n+1; i++) {
			for (j = 0; j < n+1; j++) {
				fscanf(fp_in, "%d", &(distances[i][j]));
			}
		}

		if (debug) {
			for (i = 0; i < n+1; i++) {
				for (j = 0; j < n+1; j++) {
					printf("%3d ", distances[i][j]);
				}
				printf("\n");
			}
		}


		/* main processing begins here */
		/* --------------------------- */

		/* use backtracking to generate all permutations and store the permutation giving the highest value */
		printf("value of n %d\n",n);
		fprintf(fp_out,"%d\n",k+1);
		if(n>0)
		{
			backtrack(a,0,n,distances,d,path);    // this is the original call and will just print the permutations to the terminal
		    printOutput(fp_out,record,n,path);
		}
		else{
			 printOutput(fp_out,record,n,path);
		fprintf(fp_out,"There are no deliveries\n");
		}
		// it must be modified to pass the distances array as an argument
		// so that the permutation giving the minimum distance can be identified
		// it may also be useful to have it return the permutation yielding the minimum distance
		// Remember: these permutations are for numbers 1 to n, not 0 to n-1
		// this matters when you use the permutation elements to access the distance array

		/* now process the result here ... */
		


		
		fprintf(fp_out,"\n");



		//if (debug) prompt_and_exit(1);
	}

	fclose(fp_in);
	fclose(fp_out);    
	//prompt_and_exit(0);
}