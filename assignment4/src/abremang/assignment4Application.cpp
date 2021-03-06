/* 

exampleApplication.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

The program leverages on the concept of binary search trees. 
The program creates a BST dictionary by storing unique words provides in a text file. 
The words stored in the dictionary are correctly spelt distinct words.
When all the unique words are stored, a text file with a mixture of correctly spelt and wrong 
spelt words with certain non-alphanumeric characters are read. Each word is traversed through the dictionary to determine its existence.
Words that match words in the dictionary are stored in a text tree. This facilitates printing writing words to output in an alphabetical order.
It is assumed that the first line of the input file contains
sub directory ..data/words.txt, that is it contains correctly spelt unique words to be stored in the dictionary.
Then subsequent text files contains a list of wrongly spelt words, correctly spelt words and non-alphanumeric characters.




Input
-----
the input file is made up of list of directories to filenames per line(eg. "../data/words.txt").
the first input text file is the file word file. this files contains as words for the dictionary.
the rest of the files are textfiles that contain sentences or words that would be passed through 
dictionary to determine existence.


Output
------
the first row of the output file is the andrew id "abremang"
the second to few rows below represents the data from the textfile, 
with every wrong word capitalized.
the row after provides the maximum probes made by a word in the text dictionary
the row after represents the average number of probes made by all the words in the 
text dictionary.
the rows after is made up of three columns;
the first column prints out the words stored in the text dictionary in alphabetical order.
the second column represents the frequency of the word; that is, the number of times
the word appeared in the textfile.
the final column represents the level of the word in the dictionary.

The output data from each textfile is separated by 20 dashes(--------------------).


Sample Input
------------

../data/words.txt
../data/textfile1.txt
../data/textfile2.txt


Sample Output
-------------

abremang
../data/textfile1.txt
My heart is in the work
My heart is in the WIRK
Maximum number of probes: 4
Average number of probes: 2.5
heart          2 (1) 
in             2 (3) 
is             2 (2) 
my             2 (0) 
the            2 (1) 
work           1 (2) 
--------------------
../data/textfile2.txt
heart in is My the work
Maximum number of probes: 6
Average number of probes: 3.5
heart          1 (0) 
in             1 (1) 
is             1 (2) 
my             1 (3) 
the            1 (4) 
work           1 (5) 
--------------------


Solution Strategy
-----------------
Below is an algorithm in the form of a pseudo code for the program;

Initialize the word dictionary 

reading files
---------------
Open input file and read from it 
Open output file and write to it 

Read textfile directory from input file
While (value read != end of line)
{
Initialize the text dictionary 

Open text file read
Read each word from the textfile 
While (word read != end of line character)
{
Convert word into lowercase
Remove non alphanumeric characters except hyphen

If (a word is read)
{
   If(word from the words.txt)
   {
        Store word in dictionary;
 Algorithm for storing in dictionary 
   }
Else if(word is not from words.txt)
{
       Check to see if it exists in the dictionary
If(word exists in dictionary)
{
Store it in the text tree
 	Probes = number of probes for the word
Find maximum number of probes.
}
Else if( it does not exist in dictionary)
{
	Convert to uppercase
}
}
Read the next word from the dictionary.
}
If (word is not word for the dictionary)
{
print to the output file;
maximum number of probes
average number of probes 
in alphabetical order the unique words in the text dictionary
}
Close output file 
Close input files 
}


Test Strategy
-------------

Various test cases used for the program where
................................................
-A test file with words not in the dictionary 
-a test file with no alphanumeric characters
-a dictionary with no words
-a test case with a single character 
-an empty test file
...............................................

*************************************************************************
Algorithm for tree height                                               *
--------------------------                                              *
If (tree  != null)                                                      *
{                                                                       *
Recursively call tree height (left child of tree)                       *
Recursively call tree height (right child of tree)                      *
Check if (treeheight(left child) > treeheight(left child))              *
{                                                                       *
 Maximum height = maximum tree height of left child+1                   *
}                                                                       *
Else check if (treeheight(left child) < treeheight(left child))         *
{                                                                       *
Maximum height = maximum tree height of right child+1                   *
}                                                                       *
}                                                                       *
Else If (tree is null)                                                  *
{                                                                       *
Maximum height  = 0                                                     *
}                                                                       *
                                                                        *
*************************************************************************

order of complexity 
--------------------
the order of complexity is O(n^4)
the function has four nested loops for retrieving and removing non-alphanumeric characters from word
with two insertion to the dictionary functions which are order O(log2) each.

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
18/03/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/


#include "assignment4.h"

int main() {

	bool debug            = false; // print diagnostic information?
	bool input_dictionary = true;  // we begin by reading the dictionary
	int end_of_file;
	int end_of_file2;
	int probe;
	int height, maxProbe, sumOfProbes;
	float averageProbe;
	static int heightOfTree;
	char filename[MAX_MESSAGE_LENGTH];
	char word[MAX_MESSAGE_LENGTH];
	char original_word[MAX_MESSAGE_LENGTH];
	char temp_word[MAX_MESSAGE_LENGTH];
	unsigned int i,m,j,k,numOfWords; 
	char ch;
	BINARY_TREE_TYPE dictionary_tree;
	BINARY_TREE_TYPE text_tree;
	ELEMENT_TYPE e;

	FILE *fp_in;
	FILE *fp_out;
	FILE *fp_in2;

	numOfWords = 0;
	heightOfTree =0;

	if ((fp_in = fopen("../data/input1.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}

	fprintf(fp_out,"abremang\n");

	/* read the filenames from the input file */

	end_of_file = fscanf(fp_in, "%s", filename);  // read a filename
	dictionary(&dictionary_tree);//initializing the dictionary

	while (end_of_file != EOF)
	{
		// creating an empty tree

		if (!input_dictionary) {
			height = 0;
			probe = 0;
			maxProbe=0;
			averageProbe =0;
			sumOfProbes =0;
			initialize(&text_tree);
			fprintf(fp_out,"%s\n",filename);

		}
		//printing input data as a check
		else
		{
			//printf("input data: %s\n",filename);
		}

		/* open the target file: dictionary or text */

		if ((fp_in2 = fopen(filename,"r")) == 0) {  
			printf("Error can't open text file %s\n",filename);
			prompt_and_exit(1);
		}

		end_of_file2 = fscanf(fp_in2, "%s", original_word);  // read a word from the file

		/* check the whitespace character after the word to see if it is a newline */
		ch = getc(fp_in2);
		if (ch == '\n') {
			strcat(original_word,"\n"); // add a newline character so that subsequent text in on the next line
		}
		else {
			strcat(original_word," ");  // add the whitespace
		}
		int iterations=0;

		while (end_of_file2 != EOF) 
		{
			iterations =iterations +1;
			strcpy(word,original_word); // make a copy of the word so that we can process it
			// but keep the original so that we can write it to the output file 
			strcpy(temp_word, word);
			/* convert to lower case */

			for (k=0; k< strlen(word); k++) 
			{   
				word[k] = tolower(word[k]);  
			}
			int incre=0;
			
			for (i=0; i< strlen(word); i++) 
			{
			
				if (!isalnum(word[i])) 
				{
					if ( (word[i] == '-') ) 
					{
						word[i] = word[i];
					}
					else if ( (word[i] == '\'') && (word[i+1] == 's') ) 
					{
						
						for (j=i; j<strlen(word); j++)
						{
							word[j] = word[j+2];
						}
						if(i > 0)
						{
							i=i-1;
						}
						else if(i <= 0)
						{
							i=-1;
							
						}
					}
					else 
					{
						
							for (j=i; j<strlen(word); j++)
							{ // copy the rest of the word overwriting the non-alphanumeric
								word[j] = word[j+1];
							}
							
						if(i > 0)
						{
							i = i-1;
						}
						else if(i <= 0)
						{
						   i = -1;
						}
					}
				}
			}
			bool wordExist;
			if (strlen(word) > 0)
			{

				
				/*  */

				if (input_dictionary)
				{
					dictionary_creation(word, &dictionary_tree);	
				}
				else 
				{
					/*** analyzing text ***/
					/*here is where i will find word in the dictionary, determine the level i found it*/
				     //printf("%s\n", word);
				
					assign_element_values(&e, word);

					wordExist = WordExist(e,&dictionary_tree);
				}
			}
				if (!input_dictionary)
				{
					if(wordExist == false)
					{
						for(m =0; m<strlen(original_word);m++)
						{		
							original_word[m] = toupper(original_word[m]);
						}
					}
					else
					{
					numOfWords = numOfWords +1;
						assign_element_values(&e, word);
						dictionary_creation(word, &text_tree);
						probe = probes(e,&text_tree);
						if (probe > maxProbe)
						{
							maxProbe = probe;
						}
						sumOfProbes = sumOfProbes + probe;
					}

					fprintf(fp_out,"%s", original_word);
				}
			end_of_file2 = fscanf(fp_in2, "%s", original_word);

			/* check the whitespace character to see if it is a newline */
			ch = getc(fp_in2);
			if (ch == '\n')
			{
				strcat(original_word,"\n");  // add the newline
			}
			else 
			{

				strcat(original_word," ");  // add the whitespace
			}
		}
		//print(small_tree);
		height = treeHeight(text_tree);

		/*statement the handle wrong words*/
		if(numOfWords !=0)
		{
		averageProbe = sumOfProbes/(float)numOfWords;
		}
		else if (numOfWords == 0)
		{
			averageProbe =0;
		}
		/*.......................................*/

		if (!input_dictionary) {
			fprintf(fp_out, "Maximum number of probes: %d\n", maxProbe);
			fprintf(fp_out, "Average number of probes: %3.1f\n", averageProbe);
			//fprintf(fp_out, "tree height: %3d\n", height);
			printOutput(text_tree,fp_out);
		    fprintf (fp_out,"--------------------\n");


		}
		
		fclose(fp_in2);

		end_of_file = fscanf(fp_in, "%s", filename); // read the next filename

		input_dictionary = false; // the first file is the dictionary file; we've read it so now we reset this flag
		printf("---------------------\n");
		numOfWords =0;
	};



	fclose(fp_in);
	fclose(fp_out);
	//prompt_and_exit(1);

}


