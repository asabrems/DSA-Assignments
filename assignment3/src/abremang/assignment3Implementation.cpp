/* 

exampleImplementation.cpp - implementation file for a program named example
============================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

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
02/03/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/



#include "assignment3.h"
//#include "linkedList.h"

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


int samplePoisson(double lambda) {
	/* Generate a random sample from a Poisson distribution with a given mean, lambda */
	/* Use the function rand to generate a random number */
	static bool first_call = true;
	int count;
	double product;
	double zero_probability;
	/* Seed the random-number generator with current time so */
	/* that the numbers will be different every time we run */
	if (first_call) {
		srand( (unsigned)time( NULL ));
		first_call = false;
	}
	count = 0;
	product = (double) rand() / (double) RAND_MAX;
	zero_probability = exp(-lambda);
	while (product > zero_probability) {
		count++;
		product = product * ((double) rand() / (double) RAND_MAX);
	}
	return(count);
}

/***Queues implementations**/

// enqueuing 
void enqueue(long int position, LIST_TYPE *list, ELEMENT_TYPE e, WINDOW_TYPE w, int arrival_time)
{
	assign_element_values(&e, position, arrival_time);
	w = end(list);
	insert(e, w, list);
}

void add(long int position, LIST_TYPE *list, ELEMENT_TYPE e, WINDOW_TYPE w, int arrival_time)
{
	assign_element_values(&e, position, arrival_time);
	w = end(list);
	insert(e, w, list);
}

// dequeue
ELEMENT_TYPE dequeue( LIST_TYPE list, WINDOW_TYPE w)
{
	ELEMENT_TYPE temp;


	w = first(&list);


	temp = retrieve(w, &list);
	delete_element(w, &list);


	return(temp);
}





void insertion_sort(LIST_TYPE *list , int elements_in_list, WINDOW_TYPE w)
{
	long int i,j;
	ELEMENT_TYPE e1;
	ELEMENT_TYPE e2;

	WINDOW_TYPE p;
	WINDOW_TYPE p1;
	WINDOW_TYPE p2;

	p = first(list);
	p1 = next(p, list);


	for (i=1; i< elements_in_list; i++)
	{
		j=0;
		if(p == NULL)
		{ break;}
		if((p1 == end(list)) || (p1 == NULL))
		{ 
			printf("yei\n");
			break;
		}
		else
		{
			p2 = next(p1, list);

		}
		e1 = retrieve(p,list);
		e2 = retrieve(p1,list);

		while ((((p1!= first(list)) ))&& (e2.arrival_time  < e1.arrival_time) &&(p1 != end(list)))
		{
			j=j+1;
			p->next->element.arrival_time = e2.arrival_time;
			p1->next->element.arrival_time = e1.arrival_time;

			if (p == first(list))
			{
				break;
			}
			else
			{ 
				p1 = p;
				p = previous(p,list);
				e1 = retrieve(p,list);
				e2 = retrieve(p1,list);

			}

		}
		p1 = p2;
		p = previous(p2, list);

	}
}



