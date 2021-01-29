/* 

exampleImplementation.cpp - implementation file for a program named example
============================================================================

This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

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
15/03/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/



#include "assignment4.h"
bool state;

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

ELEMENT_TYPE dictionary_creation(char word[],  BINARY_TREE_TYPE *tree)
{
	ELEMENT_TYPE e;

	assign_element_values(&e, word);
	insert(e,tree);

	return(e);

}
int getProbes(int probes)
{
	return(probes);
}
bool WordExist(ELEMENT_TYPE e ,BINARY_TREE_TYPE *tree)
{
	/* we are at an external node: create a new node and insert it */
 
	if (*tree == NULL)
	{
		/* we are at an external node: create a new node and insert it */
		state = false;
	
		
	}
	else if (strcmp(e.string , (*tree)->element.string) > 0) 
	{ /* assume the number field is the key */
		WordExist(e, &((*tree)->left));
	
	}
	
	else if (strcmp(e.string ,(*tree)->element.string) < 0) 
	{
		WordExist(e, &((*tree)->right));
	
	}
	else if (strcmp(e.string ,(*tree)->element.string)  == 0)
	{
		state =true;
		//increase the frequency count for multiple word appearance
	}

	return (state);
}

int printOutput(BINARY_TREE_TYPE tree,FILE *fp_out) {


   
   inorderOut(tree,0,fp_out);

   return(0);
}
int inorderOut(BINARY_TREE_TYPE tree, int n,FILE *fp_out) 
{

   if (tree != NULL) {

	 
      inorderOut(tree->right, n+1,fp_out);

        fprintf(fp_out,"%-10s %5d (%d) \n",  tree->element.string,tree->element.frequency,n);

      inorderOut(tree->left, n+1,fp_out);
   }
   return(0);
}

int treeHeight(BINARY_TREE_TYPE tree) {
	int maxHeight=0;
   if (tree != NULL) {
	    treeHeight(tree->left);
      treeHeight(tree->right);
	   if (treeHeight(tree->left) > treeHeight(tree->right))
	   {

		   maxHeight =treeHeight(tree->left)+1;
	   }
	   else if (treeHeight(tree->left) < treeHeight(tree->right))
	   {
		   maxHeight =treeHeight(tree->right)+1;
	   }
	   else 
	   {
		    maxHeight =treeHeight(tree->right)+1;
	   }
   }
  else if (tree == NULL)
   {
	   maxHeight = 0;
   }

   return(maxHeight);
}

int probes(ELEMENT_TYPE e ,BINARY_TREE_TYPE *tree) 
{
	/* we are at an external node: create a new node and insert it */
    int probe = 0;

	if (*tree == NULL)
	{
		/* we are at an external node: create a new node and insert it */
		probe= 0;
		
	}
	else if (strcmp(e.string , (*tree)->element.string) > 0) 
	{ /* assume the number field is the key */
		
		probe = probes(e, &((*tree)->left))+1;
		
	}

	else if (strcmp(e.string ,(*tree)->element.string) < 0) 
	{
		probe = probes(e, &((*tree)->right))+1;
	}
	else if (strcmp(e.string ,(*tree)->element.string)  == 0)
	{
		
		probe =probe+1;
	
	}
	return (probe);
}