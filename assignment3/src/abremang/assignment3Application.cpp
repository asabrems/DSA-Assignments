/* 

exampleApplication.cpp - application file for a program named example
=====================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

The functionality of the program is defined as follows.

the program simulates a single lane traffic light sequence. The program uses the Poisson function to random generate cars that join the queue.
Moreover, the simulation has a total runtime which is represented in minutes.  Like a real-life traffic light lane, at a given range of time,
a random number of cars join the queue of cars.
However, if the traffic light turns green, cars can leave the lane for a specific departure time.
Therefore, in the program, a traffic light model is also simulated.  the initial traffic light sequence is red light followed by green, then amber. 
Cars can leave the queue only if the traffic light is green.
The program also keeps tracts of various statistical values, such as the maximum length of the queue, average length of the queue, 
the median length of the queue, the maximum wait time and the average wait time. 
For the program, the maximum duration of the simulation is 10minutes. Also, the range of different test cases is between 0 to 1000.


Input
-----
The input file is made up of 8 rows of data.
First line of the input file contains a number which represents the amount of data input/ data set.
The rest of the  7 data is made up of two columns, the first column is a string and the second column is an integer;
in no particular order, the 7 data values are made up of;
meaning                            representation
arrival rate in cars per min        arrival
departure rate in seconds per car   departure
runtime in minutes,                 runtime 
time increment                      increment
duration of red light               red
duration of amber light             amber
duration of green light             green

Moreover, each data file is not separated.



Output
------
for each dataset, the output file has 11 rows of data. 
the output file begins with the andrew id "abremang",
the second row is made up of the arrival rate, which is in cars per min, 
the third row is made up of the departure rate which is measureed in seconds per car
the fourth row is made up of the runtime, which is measured in minutes
the fifth row is made up of the time increments of the total simulation, which is measured in milliseconds
the sixth row is made up of the light sequence, in the order, green, red and amber, all measured in seconds
the seventh row is made up of the average length of the cars in the queue.
the eigth row is made up of the median queue length of cars.
the nineth row is made up of the maximum length of queue in the simulation time.
the tenth row is made up of the average waiting time of a car in a queue
the eleventh row is made up of the maximum waiting time of a car in a queue.
the output of each dataset is separated by a new line

Sample Input
------------
1
Arrival 10
Departure 5
Runtime 5
Increment 10
Green 10
Amber 1
Red 30



Sample Output
-------------
abremang
Arrival rate:   10 cars per min
Departure rate: 5 s per cars
Runtime:        5 min
Time increment: 10 ms
Light sequence: Green 10 s; Amber 1 s; Red 30 s
Average length: 17 cars
Median length:  17 cars
Maximum length: 28 cars
Average wait:   110 s
Maximum wait:   218 s




Solution Strategy
-----------------
Below is an algorithm in the form of a pseudo code for the program;

reading files
---------------
Open input file and read from it 
Open output file and write to it 
Testcases = first line read from input file 
for (i =0; i< Testcases; i++)
{
For(j = 0; j< number of keys; j++)
{
Read(string(eg arrival) and its respective value(eg. 10))
Convert string to lowercase
Retrieve key values and stored them in their respective key;

simulation time
-----------------
for(i=0; i< simulation_time; i+=increment)
generate the cars using a poisson equation
for (j =0 ; j<cars; j++)
{
Equeue cars;
}

Traffic light sequence
-----------------------
If (!red light time elapse)
{
Departure =0;
Light state = red
}
If (!green light time elapse)
{
   Light state = green;
}
If(! Amber light time elapse)
{
Light state = amber;
}

If(is_departure time && light state == green)
{
Dequeue;
Get wait time;
Compare wait time to maximum wait time;
get queue length and add it to a running total of queue length;
add(queue length to linkedlist of queue lengths)
}
}

Dequeue all cars left
Add the sum of cars left in the queue to total queue length
Add the sum to the linkedlist of queue length

Insertion_sort(queue_length)
Find the median of the key length.
}
Close input and output files 





Insertion sort
---------------
For (for (i =0; i< elements_in_array; i++)
{
j=i
while((j is greater than the first value of index 0) && (current value read from array <  pervious value in array))
{
Perform a swap function.
}
}



Test Strategy
-------------
Various test cases used for the program where

- An empty dataset
- A dataset with a maximum runtime of 10mins was tested
- two or more datasets were tested
- A test case with the same departure time as green light duration 
- A test case with the arrival time =0
- A dataset with runtime =0
- A dataset with red light = 0
- A dataset with departure rate = 0

Order of complexity
--------------------
The order of complexity is O(n^3).
The reason is that, the function begins with an initial for loop of order of complexity n, 
Within the for loop are various functions and implementations.
1.	two nexted forloop for reading data input and sorting to the right key.
2.	 A forloop for the simulation time;
	a.	with the forloop is the samplePoisson function of order O(n)
	a.	within the forloop is an linkedlist enqueue of order O(n).
	b.  also within the forloop is a linkedlist  for the adding queue length O(n);

3.	a linkedlist  for the adding last queue length after the simulation O(n)
4.	An insertion sort of order of complexity O(n^2)
5.	A for loop for calculation the median O(n)
Therefore n(n^2+ n(n+ n^2 + n)+ n+ n^2+ n) = complexity of O(n^3)


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
02/03/2020


Audit Trail
-----------

- Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

#include "assignment3.h"


long int number_of_test_cases;
long int i, j,m, counter,k, count,r;
int value;

int main() 
{
	typedef char keyword[KEY_LENGTH];
	char input_string[STRING_LENGTH];
	long int arrival, departure, runtime, increment, red, amber, green;
	long int numOfCars;	// a line read from the input file
	long int cars, dequeued;
	double departure_time, arrival_time;
	double lambda;
	long int totalNumOfCars;
	long int  queue_length, average_length, MaxLength, lengthOfQueue;
	long int wait_time, maxWaitTime, avergeWaitTime;
	long int median;
	long int red_light, amber_light, green_light, light;
	double simulation_time;
	keyword key; 
	long int maxvalue;
	int debug = TRUE;
	char message[MAX_MESSAGE_LENGTH];
	char ligthState[MAX_MESSAGE_LENGTH];



	keyword keylist[NUMBER_OF_KEYS] = {
		"arrival",
		"departure",
		"runtime",
		"increment",
		"red",
		"amber",
		"green"
	};

	keyword trafficLightState[3] ={"red light","green light", "amber light"};
	//initializing a list

	WINDOW_TYPE w;
	ELEMENT_TYPE e;
	LIST_TYPE list;
	ELEMENT_TYPE e1;
	ELEMENT_TYPE car_element;
	ELEMENT_TYPE next_car_element;
	LIST_TYPE car;


	// reading input data 
	FILE *fp_in, *fp_out;
	if ((fp_in = fopen("../data/itu_morsecode_dictionary.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}
	fgets(input_string, STRING_LENGTH, fp_in);
	while (sscanf(input_string, " %s", key) != EOF)
	{
	printf("value ooo %s\n",input_string);
	fgets(input_string, STRING_LENGTH, fp_in);
	}
	// reading data file 
	/*
	fscanf(fp_in, "%d", &number_of_test_cases); 
	printf("number of test cases %d\n",number_of_test_cases);
	fgets(input_string, STRING_LENGTH, fp_in); 
	fprintf(fp_out,"abremang\n");


	for (m= 0; m < number_of_test_cases; m++)
	{
		
		initialize_list(&list); 
		empty(&list);
		initialize_list(&car); 
		empty(&car);

		
		value = 0;
		arrival =0;
		departure =0;
		runtime =0;
		increment =0;
		red =0;
		amber =0;
		green =0;
		
		numOfCars =0;
		cars =0;
		arrival_time =0;
		lambda =0;
		departure_time = 0;
		dequeued =0;
		queue_length = 0;
		wait_time =0;
		maxWaitTime =0;
		avergeWaitTime =0;
		red_light =0;
		amber_light =0;
		green_light =0;
		light =0;
		average_length =0;
		totalNumOfCars =0;
		MaxLength =0;
		lengthOfQueue =0;
		median =0;
		simulation_time =0;
	

		for(k=0; k<NUMBER_OF_KEYS; k++)
		{
			fgets(input_string, STRING_LENGTH, fp_in);
			sscanf(input_string, " %s %d", key, &value);

			for (j=0; j < (int) strlen(key); j++)
			{
				key[j] = tolower(key[j]);
			}
			printf("Key value pair %s, %d\n", key, value);
			for (int l=0; l<NUMBER_OF_KEYS; l++)
			{

				if (strcmp(key, "increment") == 0)
				{ 
					increment = value; 
				}
				if (strcmp(key, "arrival") == 0)
				{
					arrival = value; 
				}
				if (strcmp(key, "departure") == 0)
				{
					departure = value; 
				}
				if (strcmp(key, "runtime") == 0)
				{
					runtime = value; 
				}
				if (strcmp(key, "red") == 0)
				{
					red = value; 
				}
				if (strcmp(key, "amber") == 0)
				{
					amber = value; 
				}
				if (strcmp(key, "green") == 0)
				{
					green = value; 
				}

			}

		}
		if(arrival == 0 || runtime ==0)
		{
			printf("Invalid input");
			continue;
		}

		//changing the traffic lights to milliseconds
		amber_light = amber*1000;
		green_light = green*1000;
		red_light =red*1000;



		arrival_time = ((float)arrival)/(60*1000);
		simulation_time = runtime*60*1000;
		for(i=0; i< simulation_time; i+=increment)
		{
			lambda = arrival_time*increment;

			cars = samplePoisson(lambda);
			for (j =0 ; j<cars; j++)
			{
				numOfCars = numOfCars +  1;
				totalNumOfCars = totalNumOfCars +1;

				enqueue(numOfCars, &list, e, w, i);
			}

			if(light <= ( red_light))
			{
				departure_time = 0;
				strcpy(ligthState,trafficLightState[0]);
			}
			else{

				if((light <= (red_light + green_light)))
				{
					strcpy(ligthState,trafficLightState[1]);

				}
				else
				{
					if((light <= (red_light+ green_light+ amber_light)))
					{
						strcpy(ligthState,trafficLightState[2]);
					}
					else
					{
						light = 0 ;

					}
				}
			}



		
			if((departure_time >= (departure*1000)) && (strcmp(ligthState ,"green light")==0))
			{
			if(!is_empty(&list))
			{
				e1 = dequeue(list, w);
				dequeued = dequeued +1;
				wait_time = (i - e1.arrival_time)/1000;
				avergeWaitTime = avergeWaitTime + wait_time;
				numOfCars = numOfCars -1;
				add(dequeued, &car, e, w, numOfCars);// adding to the queuelength queue
				if(wait_time > maxWaitTime)
				{
					maxWaitTime = wait_time;
				}


			}
			if(numOfCars > MaxLength)
			{
				MaxLength = numOfCars;
			}
			average_length = average_length + numOfCars;
			departure_time = 0;
			}
			lengthOfQueue = dequeued;
		

			departure_time = departure_time + increment;
			light = light + increment;
		}

		while(!is_empty(&list))
		{
			e1 = dequeue(list,w);
			count = count +1;
			dequeued = dequeued +1;
			wait_time = (i - e1.arrival_time)/1000;
			if(wait_time > maxWaitTime)
			{
				maxWaitTime = wait_time;
			}
			avergeWaitTime = avergeWaitTime + wait_time;
		
		}
		if(count > MaxLength)
		{
			MaxLength = count;
		}

		add(lengthOfQueue+1, &car, e, w, count );

		//print(&car);
		if(!is_empty(&car))
		{
			w = first(&car);
			insertion_sort(&car,lengthOfQueue+1,w);
	
			for(r = 0; r < (lengthOfQueue+1); r++)
			{ 
				car_element = retrieve(w, &car);

				if(car_element.number == ((int)(lengthOfQueue+1)/2))
				{ 
					if((lengthOfQueue+1 %2) != 0)
					{
						next_car_element = retrieve(next(w, &car), &car);
						median = (car_element.arrival_time + next_car_element.arrival_time)/2;
					}
					else
					{
						median = car_element.arrival_time;
					}
					break;

				}
				if(w == end(&car))
				{
					break;
				}
				else
				{
					w = next(w, &car);
				}

			}

		}
		else
		{
			printf("list no dey oo");
		}
		average_length = average_length + count;
		avergeWaitTime = avergeWaitTime/dequeued;
		//printf("average wait time2: %d\n",avergeWaitTime);
		average_length = average_length/(lengthOfQueue+1);

		fprintf(fp_out,"Arrival rate:   %ld cars per min\n", arrival);
		fprintf(fp_out,"Departure rate: %ld s per cars\n", departure);
		fprintf(fp_out,"Runtime:        %ld min\n", runtime);
		fprintf(fp_out,"Time increment: %ld ms\n", increment);
		fprintf(fp_out,"Light sequence: Green %d s; Amber %d s; Red %d s\n", green, amber, red);
		fprintf(fp_out,"Average length: %ld cars\n", average_length);
		fprintf(fp_out,"Median length:  %ld cars\n", median);
		fprintf(fp_out,"Maximum length: %ld cars\n", MaxLength);
		fprintf(fp_out,"Average wait:   %ld s\n", avergeWaitTime);
		fprintf(fp_out,"Maximum wait:   %ld s\n", maxWaitTime);
		fprintf(fp_out,"\n"); 

	}*/

	fclose(fp_in);
	fclose(fp_out);
	prompt_and_exit(1);

}

