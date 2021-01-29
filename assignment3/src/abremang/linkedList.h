/************************************************************************/
/*                                                                      */
/* Interface file for linked-list implementation of a LIST ADT          */
/*                                                                      */
/* The list element type is a structure comprising an integer & string  */
/* The list itself is implemented as a singly linked list of elements   */
/* The ADT list operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/*                                                                      */
/* 26/02/2018 changed delete() to delete_element() in order to avoid    */
/* conflict with the inbuilt delete function in C++                     */
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

/*typedef  struct {
            int number;
            char *string;
         } ELEMENT_TYPE;*/

typedef  struct {
            int number;
            long int arrival_time;
         } ELEMENT_TYPE;


typedef struct node *NODE_TYPE;

typedef struct node {
            ELEMENT_TYPE element;
            NODE_TYPE next;
         } NODE;

typedef NODE_TYPE LIST_TYPE;

typedef LIST_TYPE WINDOW_TYPE;

/*** function prototypes ***/


/*** initialize the list pointer to make sure all subsequent checks on its value are valid ***/

void initialize_list(LIST_TYPE *list);


/*** position following last element in a list ***/

WINDOW_TYPE end(LIST_TYPE *list);

/*** empty a list ***/

WINDOW_TYPE empty(LIST_TYPE *list);

/*** test to see if a list is empty  ***/

int is_empty(LIST_TYPE *list);

/*** position at first element in a list ***/

WINDOW_TYPE first(LIST_TYPE *list);

/*** position at last element in a list ***/

WINDOW_TYPE last(LIST_TYPE *list);

/*** position at next element in a list ***/

WINDOW_TYPE next (WINDOW_TYPE w, LIST_TYPE *list);

/*** position at previous element in a list ***/

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list);

/*** insert an element in a list ***/

LIST_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, LIST_TYPE *list );

/*** delete an element in a list ***/

LIST_TYPE *delete_element (WINDOW_TYPE w, LIST_TYPE *list);

/*** retrieve an element in a list ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list);

/*** print all elements in a list ***/

int print(LIST_TYPE *list);

/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s);

/*** assign values to an element ***/

//int assign_element_values (ELEMENT_TYPE *e, int number, char s[]);
int assign_element_values(ELEMENT_TYPE *e, int number, long int arriv);
