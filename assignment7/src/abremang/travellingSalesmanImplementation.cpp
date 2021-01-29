/* 

travellingSalesmanImplementation.cpp - application file for the solution of the travelling saleman problem by exhaustive search using backtracking

04-630 Data Structures and Algorithms for Engineers Assignment No. 7

The backtracking code is based on the examples in S. Skiena, The Algorithm Design Manual, 2008.
David Vernon
16 April 2018

*/

#include "travellingSalesman.h"
//int distancesum =0;
/* original backtracking code ... needs to be adapted for the assignment */

int optdistance = 1000;

void backtrack(int a[], int k, int input, int distance[][NUMBER_OF_STOPS], int d[], int path[]) {

	int c[MAXCANDIDATES];     /* candidates for next position  */
	int ncandidates;          /* next position candidate count */
	int i;  
	int mindistance =0;/* counter                       */
	int distanceSum =0;
	int distanceSoFar=0;



	if (is_a_solution(a,k,input)) 
	{

		d[k]= distance[a[k]-1][input];
		for(int y =0; y<=k;y++)
		{  
			distanceSum= distanceSum+d[y];
		}
		if(distanceSum < optdistance)
		{
			optdistance = distanceSum;
			process_solution(a,k,input,path);
			printf("optdistance %d\n\n",  optdistance );

		}

		mindistance =optdistance;
	} 
	else {
		k = k+1;
		construct_candidates(a,k,input,c,&ncandidates); 

		for (i=0; i<ncandidates; i++)
		{
			distanceSoFar=0;
			a[k] = c[i];

			if(k>1)
			{
				d[k-1] = distance[a[k-1]-1][c[i]-1];
			}
			else{

				d[k-1] =distance[input][c[i]-1];
			}
			for (int w=0; w<k;w++)
			{
				distanceSoFar = distanceSoFar + d[w];
			}
			//this condition implements prunning
			if(distanceSoFar < optdistance){
				backtrack(a,k,input, distance,d,path);
			}

		}
	}
}



bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}

//returns the optimal minimum distance
int getvalue()
{
	return optdistance;
}

//resets the optimal minimum distance
void setValue(int value)
{
	optdistance = value;
}


void process_solution(int a[], int k, int input, int path[]) {

	int i;                       /* counter */
	bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

	print_permuations = true;    /* set to true if you want the permutations printed to the terminal; false otherwise */

	if (print_permuations) {
		for (i=1; i<=k; i++) {
			path[i] =a[i];
			printf(" %d",a[i]);
		}
		printf("\n");
	}

}


void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {

	int i;                       /* counter */
	bool in_perm[NMAX];          /* who is in the permutation? */
	for (i=1; i<NMAX; i++) {     /* NB: NMAX must be the number of elements in the permutation + 1 to allow for counting from 1, rather than 0 */
		in_perm[i] = FALSE;
	}

	/* the original Skiena code is incorrect ... a[i(==0)] is not a valid element of the permutation since we start storing them at a[1]

	for (i=0; i<k; i++) in_perm[ a[i] ] = TRUE;

	*/

	for (i=1; i<k; i++) in_perm[ a[i] ] = TRUE; // we are finding candidates for a_k, a_k+1, ... a_n
	// when k == 1, all candidates are valid because we haven't selected any yet
	// when k == 2, all candidates except a_1 are valid
	// when k == n, all candidates except a_1 .. a_n-1 are valid
	*ncandidates = 0;
	for (i=1; i<=n; i++) {
		if (in_perm[i] == FALSE) {
			c[ *ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}

void printOutput(FILE* fp_out,record_type record[],int n,int path[])
{
	if(n>0)
	{
	fprintf(fp_out,"%d\n",optdistance);
	}
	else{
	fprintf(fp_out,"%d\n",0);
	}
	fprintf(fp_out,"%s\n",record[n].string);
	for(int r=1; r<=n;r++)
	{

		fprintf(fp_out,"%s\n",record[path[r]-1].string);

	}
	fprintf(fp_out,"%s\n",record[n].string);
	optdistance = 1000;
}

void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void remove_new_line(char string[]) {
	int i;

	i=0;
	while(string[i] != '\0' && string[i] != '\n')
		i++;
	string[i] = '\0';
}

