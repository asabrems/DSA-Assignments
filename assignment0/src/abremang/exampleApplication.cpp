/* 

   exampleApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
   Read a single-line message from an input file, write it to the terminal, and also write a version of it to an output file.
   The message to be written to file should be prepended with the following text:

   "The message is: "

   A function is used to prepend the text and write the message to the output file.

   Input data with a test case message is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"

   There are a maximum of eighty of characters in the message.  If message has more than eighty characters, only the first eighty are read.


   Input
   -----

   - A single line of text no longer than 80 characters.


   Output
   ------

   - A single line of text, beginning "The message is: "
 

   Sample Input
   ------------
   
   Hello World!


   Sample Output
   -------------

   The message is: Hello World!


   Solution Strategy
   -----------------

   This is just an example program so there is no real computational problem to solve.  In other cases, you would describe here
   the principle computational theories used in solving the problem, along with the main data structures and algorithms used.


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - message with no character
   - message with number of characters in the range 1-80
   - message with more than eighty characters



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

   David Vernon, Carnegie Mellon University Africa
   05/01/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/
#ifdef compile 
#include "example.h"
 
int main() {

   int debug = TRUE;
   char message[MAX_MESSAGE_LENGTH];

   FILE *fp_in, *fp_out;

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }

   /* read the message from the input file */

   fgets(message, MAX_MESSAGE_LENGTH, fp_in);
 
   if (debug) printf ("%s\n",message);

   print_message_to_file(fp_out, message);

   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
#endif 
#ifdef compile
/* Example 1                                       */
/* This is a C program to ask you to type a letter */
/* and then to tell you what you typed             */

#include <stdio.h>
  #include <conio.h>// allows to read characters 
void main() { 
   char letter;

   printf("Please type a letter & then press Return >>");
   scanf("%c",&letter);
   printf("You typed the letter %c", letter);
   printf("\nPress any key to continue\n");
   _getch();
}
#endif 
#ifdef compile
/* Example 2                                       */
/* This is a C program to ask you to enter two     */
/* numbers; it then compares them and prints a     */
/* message to say whether they are equal or not    */

#include <stdio.h> 
#include <conio.h>
void main() {
 
   int first_number, second_number;

   printf("Type a number and then press Enter >>");
   scanf("%d",&first_number);

  printf("Type another number and then press Enter >>");
  scanf("%d",&second_number);

  if (first_number == second_number) 
     printf("The two numbers %d are identical", first_number);
  else
     printf("The two numbers %d and %d are different",  first_number, second_number);
 printf("\nPress any key to continue\n");
  _getch();
}
#endif 

/* Example 3a                                        */
/* Compute the total value of 7 Scrabble letters     */
/* Input:  the user is prompted to enter each letter */
/*         in turn                                   */
/* Output: the program prints the sum of the seven   */
/*         individual letter values                  */
 
#include <stdio.h> 
#include <ctype.h>

#define TRUE  1 
#define FALSE 0

void main() {

   char letter, enter;
   int scrabble_value, 
       total_scrabble_value,   
       i;   /*  not the same as 'i'  */
   int debug; 

 
   /* debug is a flag.  If it is TRUE we will execute some printf */
   /* statements to help see what the program is doing.           */
   /* if it is FALSE, we won't!                                   */

   debug = TRUE;

   /* initialize variables */

   total_scrabble_value = 0;
   scrabble_value = 0;

   /* use a for loop to read seven values*/

   for (i=0; i < 7; i++) 
   {
      printf("Please type a letter and then press Return >>");
      scanf("%c",&letter);
      scanf("%c",&enter);        /* skip enter character */

      letter = toupper(letter);  /* convert the letter to uppercase    */
                                 /* note this works even if the letter */
                                 /* is already in upper case           */

      if ((letter == 'A') || 
          (letter == 'E') ||
          (letter == 'I') || 
          (letter == 'L') || 
          (letter == 'N') || 
          (letter == 'O') || 
          (letter == 'R') || 
          (letter == 'S') || 
          (letter == 'T') || 
          (letter == 'U')) 

      {
         scrabble_value = 1;
         if (debug == TRUE)
            printf("the letter %c has the value %d\n", letter, scrabble_value);
      }
      else 
         if ((letter == 'D') || 
             (letter == 'G')) 
         {
            scrabble_value = 2;
            if (debug == TRUE) {
               printf("the letter %c has the value %d\n", letter, scrabble_value);
            } 
         } 
         else 
            if ((letter == 'B') || 
                (letter == 'C') || 
                (letter == 'M') || 
                (letter == 'P')) 
            { 
               scrabble_value = 3;
               if (debug == TRUE)
                  printf("the letter %c has the value %d\n", letter, scrabble_value);
            } 
            else 
               if ((letter == 'F') || 
                   (letter == 'H') || 
                   (letter == 'V') || 
                   (letter == 'W') || 
                   (letter == 'Y')) 
               { 
                 scrabble_value = 4;
                  if (debug == TRUE)
                     printf("the letter %c has the value %d\n", letter, scrabble_value);
               } 
               else 
                  if ((letter == 'K')) 
                  {
                     scrabble_value = 5;
                     if (debug == TRUE)
                        printf("the letter %c has the value %d\n", letter, scrabble_value);
                  } 
                  else 
                     if ((letter == 'J') || 
                         (letter == 'X') ) 
                     {
                        scrabble_value = 8;
                        if (debug == TRUE)
                           printf("the letter %c has the value %d\n", letter, scrabble_value);
                     } 
                     else 
                        if ((letter == 'Z') || 
                            (letter == 'Q') ) 
                        {
                           scrabble_value = 10;
                           if (debug == TRUE)
                              printf("the letter %c has the value %d\n", letter, scrabble_value);
                        } 
   
                        else

                           printf("You typed the character %c ... that's not allowed\n", letter);

      /* now add the value to the total */
      
      total_scrabble_value = total_scrabble_value + scrabble_value;
  }  
 
   printf("The Scrabble value of the seven letters is %d", 
           total_scrabble_value);
} 