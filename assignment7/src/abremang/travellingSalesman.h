/* 

   travellingSalesman.h - interface file for the solution of the travelling saleman problem 
   by exhaustive search using backtracking and pruning.

   04-630 Data Structures and Algorithms for Engineers Assignment No. 7


   David Vernon
   15 April 2020

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define STRING_SIZE 80
#define NUMBER_OF_STOPS 11
#define MAXCANDIDATES NUMBER_OF_STOPS
#define NMAX NUMBER_OF_STOPS


/* data structure to represent a customer or restaurant */

struct record_type {
   int  key;                  // an integer that will be used in the permutation instead of the string
   char string[STRING_SIZE];  // the string representing the customer name and address or restaurant name and address
};


/* function prototypes */
/* ------------------- */

/* utility function to remove a newline character that may have been included when parsing the input data */
void remove_new_line(char string[]);

void prompt_and_exit(int status);

void backtrack(int a[], int k, int n, int distance[][NUMBER_OF_STOPS], int d[],int path[]);                                                // original backtrack 
bool is_a_solution(int a[], int k, int n);                                            // 
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);          // permutation construct_candidates
void process_solution(int a[], int k, int n, int path[]);                                         // original process_solution 
int getvalue();
void setValue(int value);

void printOutput(FILE* fp_out,record_type record[],int n,int path[]);

 