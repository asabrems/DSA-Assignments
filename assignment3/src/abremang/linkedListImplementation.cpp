/************************************************************************/
/*                                                                      */
/* Implementation file for linked-list implementation of a LIST ADT     */
/*                                                                      */
/* The list element type is a structure comprising an integer & string  */
/* The list itself is implemented as a singly linked list of elements   */
/* The ADT list operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/*                                                                      */
/************************************************************************/

#include "linkedList.h"
 

/*** initialize the list pointer to make sure all subsequent checks on its value are valid ***/

void initialize_list(LIST_TYPE *list) {
  *list = NULL;
  

   /* we don't know what value *tree has when the program is launched      */
   /* so we have to be careful not to dereference it                       */
   /* if it's the first call to initialize, there is no tree to be deleted */
   /* and we just set *tree to NULL                                        */
   /* static bool first_call = true;
   if (first_call) {
      first_call = false;
      *list = NULL;
   }
   else {
      if (*list != NULL) empty(list);
      *list= NULL;
   }*/
}


/*** position following last element in a list ***/

WINDOW_TYPE end(LIST_TYPE *list) {

   WINDOW_TYPE q;
   
   q = *list;

   if (q == NULL) {
      error("non-existent list");
   }
   else {
      while (q->next != NULL) {
         q = q->next;
      }
   }
   return(q);
}


/*** empty a list ***/

WINDOW_TYPE empty(LIST_TYPE *list) {

   WINDOW_TYPE p, q;
   
   if (*list != NULL) {

      /* list exists: delete all nodes including the header */

      q = *list;

      while (q->next != NULL) {
         p = q;
         q = q->next;
         free(p);
      }
   }
 
   /* now,  create a new empty one with a header node */
      
   if ((q = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
      error("function empty: unable to allocate memory");
   else {
      q->next = NULL;
      *list = q;
   }
   return(end(list));
}


/*** test to see if a list is empty  ***/

int is_empty(LIST_TYPE *list) {

   WINDOW_TYPE q;
   
   q = *list;

   if (q == NULL) {
      error("non-existent list");
   }
   else {
      if (q->next == NULL) 
         return(TRUE);
      else
         return(FALSE);
   }
}


/*** position at first element in a list ***/

WINDOW_TYPE first(LIST_TYPE *list) {

   if (is_empty(list) == FALSE)
      return(*list);
   else
      return(end(list));
}


/*** position at last element in a list ***/

WINDOW_TYPE last(LIST_TYPE *list) {

   WINDOW_TYPE p, q;
   
   if (*list == NULL) {
      error("last: non-existent list");
   }
   else {

      /* list exists: find last node */

      if (is_empty(list)) {
         p = end(list);
      }
      else {
         p = *list;
         q = p->next;

         while (q->next != NULL) {
            p = q;
            q = q->next; 
         }
      }
      return(p);
   }
 }


/*** position at next element in a list ***/

WINDOW_TYPE next (WINDOW_TYPE w, LIST_TYPE *list) {

   if (w == last(list)) {
      return(end(list));
   }
   else if (w == end(list)) {
      error("can't find next after end of list");
   }
   else {
      return(w->next);
   }
}


/*** position at previous element in a list ***/

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {

   WINDOW_TYPE p;

   if (w != first(list)) {

      p = first(list);
      while (p->next != w) {
         p = p->next;
         if (p == NULL) break;  /* trap this to ensure we don't dereference */
                                /* a null pointer in the while condition    */
      }

      if (p != NULL)
        return(p);
      else {
        error("can't find previous to a non-existent node ");
        return (w);
      }
   }
   else {
      error("can't find previous before first element in list");
      return(w);
   }
}


/*** insert an element in a list ***/

LIST_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, LIST_TYPE *list ) {

   WINDOW_TYPE temp;

   if (*list == NULL) {
      error("cannot insert in a non-existent list");
   }
   else {

      /* insert it after w */

      temp = w->next;
      if ((w->next = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
         error("function insert: unable to allocate memory");
      else {
         w->next->element = e;
         w->next->next = temp;
      }
      return(list);
   }
}


/*** delete an element in a list ***/

LIST_TYPE *delete_element (WINDOW_TYPE w, LIST_TYPE *list) {

   WINDOW_TYPE p;

   if (*list == NULL) {
      error("cannot delete from a non-existent list");
   }
   else {

      p = w->next; /* node to be deleted */

      w->next = w->next->next; /* rearrage the links */

      free(p); /* delete the node */

      return(list);
   }
}


/*** retrieve an element in a list ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list) {

   if (*list == NULL) {
      error("cannot retrieve from a non-existent list");
   }
   else {
      return(w->next->element);
   }
}


/*** print all elements in a list ***/

/*int print(LIST_TYPE *list) {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;

   printf("Contents of list: \n");

   w = first(list);

   while (w != end(list)) {

      e = retrieve(w, list);
      
      printf("%d %s\n", e.number, e.string);

      w = next(w, list);
   }

   printf("--- \n");

   return(0);
}*/
int print(LIST_TYPE *list) {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;

   printf("Contents of list: \n");

   w = first(list);

   while (w != end(list)) {

      e = retrieve(w, list);
      
      printf("%d %d\n", e.number, e.arrival_time);

      w = next(w, list);
   }

   printf("--- \n");

   return(0);
}


/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s) {
   printf("Error: %s\n",s);
   exit(0);
}

/*** assign values to an element ***/

/*int assign_element_values(ELEMENT_TYPE *e, int number, char s[]) {

   e->string = (char *) malloc(sizeof(char) * (strlen(s)+1));

   if (e->string==NULL) printf("Failed to allocate memory \n"); 

   strcpy(e->string, s);

   e->number = number;
   
   return(0);
}*/
int assign_element_values(ELEMENT_TYPE *e, int number, long int arriv) 
{

   e->arrival_time = arriv;

   e->number = number;
   
   return(0);
}


