/* 

Implementation file

Graph - adjacency list implementation based on code by Steven Skiena:

Steven S. Skiena, "The Algorithm Design Manual", 2nd Edition, Springer, 2008.

David Vernon
19 March 2017

*/

#include "graph.h"

/* Breadth-First Search data structures */

bool processed[MAXV+1];   /* which vertices have been processed */
bool discovered[MAXV+1];  /* which vertices have been found */
int  parent[MAXV+1];      /* discovery relation */
int entry_time[MAXV+1];
int min_weight[MAXV+1];
int exit_time[MAXV+1];
int time = 0;
int count;
int minweight = 4000;
int get = 900;
int path[MAXV+1];
bool debug = true;

/* Initialize graph  */

void initialize_graph(graph *g, bool directed){

	int i;                          /* counter */

	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;

	for (i=1; i<=MAXV; i++) 
		g->degree[i] = 0;

	for (i=1; i<=MAXV; i++) 
		g->edges[i] = NULL; 
}

/* Initialize graph from data in a file                             */
/* return false when the number of vertices is zero; true otherwise */

bool read_graph(graph *g, bool directed) { 

	int i;    /* counter                */
	int m;    /* number of edges        */
	int x, y; /* vertices in edge (x,y) */
	int w;    /* weight on edge (x,y)   */

	initialize_graph(g, directed);

	printf("Enter the number of vertices >> ");
	scanf("%d",&(g->nvertices));
	printf("Enter the number of edges    >> ");
	scanf("%d",&m);

	//if (debug) printf("%d %d\n",g->nvertices,m);

	if (g->nvertices != 0) {
		for (i=1; i<=m; i++) {
			printf("Enter edge vertices, x and y, and weight, w >> ");
			scanf("%d %d %d",&x,&y,&w);
			//if (debug) printf("%d %d %d\n",x,y,w);
			insert_edge(g,x,y,directed, w);
		} 
		return(true); 
	}
	else {
		return(false);
	}
}  

/* insert edge in a graphs */
int graphchange(int v, int value)//, graph *g)
{
	int val;
	if(v > -1 )
	{
		val = parent[v];
		parent[v] = value;
	}
	return (val);
}
void insert_edge(graph *g, int x, int y, bool directed, int w) {

	edgenode *p;                  /* temporary pointer */

	p = (EDGENODE_PTR) malloc(sizeof(edgenode)); /* allocate edgenode storage */
	//^^^^^^^^^^^^^^ ADDED CAST. DV 7/11/2014

	p->weight = w;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;              /* insert at head of list        */

	g->degree[x] ++;

	if (directed == false)        /* NB: if undirected add         */
		insert_edge(g,y,x,true,w); /* the reverse edge recursively  */  
	else                          /* but directed TRUE so we do it */
		g->nedges ++;              /* only once                     */
}

void find_vertex(graph *g, int y,int x, bool directed) 
{

	int y_next=0;
	edgenode *p;
	edgenode *p_temp;
	/* temporary pointer */
	p = g->edges[x];
	if((p->y == y) && (p != NULL))
	{
		g->edges[x] = p->next;
		min_weight[p->y]= -1;
		//free(p);
	 
	}
	else
	{
		while((p->y != y) && (p != NULL))
		{

			p_temp = p;
			p = p->next;

		}
		if(p->y == y)
		{
			p_temp->next = p->next;
			min_weight[p->y]= -1;
			//free(p);
		}
	}
	if (directed == FALSE)
	{
		find_vertex(g, x, y, TRUE);
	}
	                
}

/*void block_edge(graph *g, int y,int x)
{
	find_vertex(g, y, x);
	find_vertex(g, x, y);

}*/

/* Print a graph                                                    */

void print_graph(graph *g) {

	int i;                             /* counter           */
	edgenode *p;                       /* temporary pointer */

	printf("Graph adjacency list:\n");

	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != NULL) {

			printf(" %d-%d", p->y, p->weight);

			p = p->next;
		}
		printf("\n");
	}
	printf("nvertices %d\n",g->nvertices);
	printf("nedges    %d\n",g->nedges);

}

/* Each vertex is initialized as undiscovered:                      */

void initialize_search(graph *g)
{

	int i;                          /* counter */

	for (i=1; i<=g->nvertices; i++) 
	{
		processed[i] = discovered[i] = FALSE;
		parent[i] = -1;
		min_weight[i] = 0;
		path[i] =0;
	} 
}

/* Once a vertex is discovered, it is placed on a queue.           */
/* Since we process these vertices in first-in, first-out order,   */
/* the oldest vertices are expanded first, which are exactly those */
/* closest to the root                                             */

void bfs(graph *g, int start)
{
	queue q;                  /* queue of vertices to visit */
	int v;                    /* current vertex             */
	int y;   
	int w;/* successor vertex           */
	edgenode *p;              /* temporary pointer          */
	get = 900;
	init_queue(&q);
	enqueue(&q,start);
	discovered[start] = TRUE;
	while (empty_queue(&q) == FALSE) 
	{	v = dequeue(&q);
	process_vertex_early(v);
	processed[v] = TRUE;
	p = g->edges[v];

	while (p != NULL) {  
		if (p->weight>0)
		 {
			 y = p->y;
			 if ((processed[y] == FALSE) || g->directed)
				process_edge(v,y);
			 if (discovered[y] == FALSE) {
				enqueue(&q,y);
				discovered[y] = TRUE;
				parent[y] = v;
			 }
		 }
		p = p->next; 
	}
	process_vertex_late(v);
	}

}

int bfs_fire(graph *g, int start)
{
	queue q;                  /* queue of vertices to visit */
	int v;                    /* current vertex             */
	int y; 
	int mw= 45678;
	int count=0;
	int w;/* successor vertex           */
	edgenode *p;              /* temporary pointer          */
	initialize_search(g);
	//minweight= 30000;
	init_queue(&q);
	enqueue(&q,start);
	discovered[start] = TRUE;

	while (empty_queue(&q) == FALSE) 
	{	v = dequeue(&q);
	process_vertex_early(v);
	processed[v] = TRUE;
	p = g->edges[v];
	count = count+ 1;

	while (p != NULL) 
	{  

		y = p->y;
		w= p->weight;
		/*if ((processed[y] == FALSE) || g->directed)
		{
		//printf("discovered %d\n",y);
		process_edge(v,y);
		//min_weight[y] = w;
		}*/
		if (discovered[y] == FALSE)
		{
			//printf("undiscovered zone, parent:%d edge:%d weight:%d\n",v,y,w);
			//printf("not discovered %d\n",y);
			enqueue(&q,y);
			discovered[y] = TRUE;
			parent[y] = v;
			min_weight[y] = w;
			//printf("undiscovered zone, parent:%d edge:%d weight:%d\n",v,y,w);
		}
		else if (discovered[y] == TRUE && (processed[y] == FALSE))
		{
			//w= p->weight;
			if (w > min_weight[y])
			{

				parent[y] = v;
				min_weight[y]= w;
				//printf("discovered zone1, parent:%d edge:%d weight:%d\n",v,y,w);

			}
			else if (w < min_weight[y])
			{
				if (min_weight[v] < w)
				{
					min_weight[v]= w;
					parent[v] = y;
					//printf("discovered zone2, parent:%d edge:%d weight:%d\n",v,y,min_weight[v]);
				}
			}

		}

		p = p->next; 
	}
	process_vertex_late(v);
	}
	for (int g=1; g<count+1; g++)
	{
		printf("%d %d\n",min_weight[g], parent[g]);
		if ( mw > min_weight[g] &&(min_weight[g] !=0))
		{
			mw = min_weight[g];
		}

	}
	return(mw);
}
void insertion_sort(queue1 *qA)
{
	int i,j;
	vals temp;
	float prior_value = 0;
	float current_value = 0;
	int temp_value;
	current_value = 0;
	current_value =0;
	//empty_queue1(qA) == FALSE;
	for (i=1; i< qA->last; i++)
	{
		j=i;
		current_value = qA->q[j].weights;//._sorted; 
		prior_value =qA->q[j-1].weights;


		while ((j>0) && (current_value  < prior_value) )
		{

			temp = qA->q[j-1]; // swap
			qA->q[j-1] = qA->q[j];
			qA->q[j] = temp;
			j = j-1;

			current_value = qA->q[j].weights;//._sorted; 
			prior_value =qA->q[j-1].weights;


		}
	}
}
/* The exact behaviour of bfs depends on the functions             */
/*    process vertex early()                                       */
/*    process vertex late()                                        */
/*    process edge()                                               */
/* These functions allow us to customize what the traversal does   */
/* as it makes its official visit to each edge and each vertex.    */
/* Here, e.g., we will do all of vertex processing on entry        */
/* (to print each vertex and edge exactly once)                    */
/* so process vertex late() returns without action                 */

/*void process_vertex_late(int v) {
}

void process_vertex_early(int v){
//printf("processed vertex %d\n",v);
}

void process_edge(int x, int y) {
//printf("processed edge (%d,%d)\n",x,y);
}*/



int CC(graph *g)
{
	int c;
	int i;
	initialize_search(g);
	c=0;
	for (i=1; i<=g->nvertices; i++)
	{
		if(discovered[i] == FALSE)
		{
			c= c+1;
			bfs(g,i);
		}

	}
	return (c);
}
/* The exact behaviour of bfs depends on the functions             */
/*    process vertex early()                                       */
/*    process vertex late()                                        */
/*    process edge()                                               */
/* These functions allow us to customize what the traversal does   */
/* as it makes its official visit to each edge and each vertex.    */
/* Here, e.g., we will do all of vertex processing on entry        */
/* (to print each vertex and edge exactly once)                    */
/* so process vertex late() returns without action                 */

void process_vertex_late(int v) {
}

void process_vertex_early(int v){
	//printf("processed vertex %d\n",v);
}

void process_edge(int x, int y)
{
	//printf("processed edge (%d,%d)\n",x,y);
}
/* this version just counts the number of edges                     */
/*
void process_edge(int x, int y) {
nedges = nedges + 1;
}
*/


/* adapted from original to return true if it is possible to reach the end from the start */

bool find_path(int start, int end, int parents[],int weight[], FILE *fp_out) {

	bool is_path;
	count = 0;
	//printf("value %d\n",minweight);
	//minweight = weight[end];

	if (end == -1) {
		is_path = false; // some vertex on the path back from the end has no parent (not counting start)
		if (debug) printf("\nis_path is false: ");

	}
	else if ((start == end)) {
		if (debug)
		{printf("\n%d",start);
		path[count]=start;
		count = count+1;

		}
		is_path = true; // we have reached the start vertex
	}
	else {
		 printf("value %d\n",weight[end]);
		if (((get) > weight[end]) &&((weight[end]>0 )&&(get >0)))
		{
			printf("i am in\n");
			get =  weight[end];
			printf("min weight: %d\n", get);
		}
		is_path = find_path(start,parents[end],parents,weight,fp_out);

		if (debug) 
		{printf(" %d",end);
		path[count]=end;
		count = count+1;
		}
	}
	return(is_path); 
}

void print_path(FILE *fp_out)
{
	int i;
	fprintf(fp_out,"Route = ");
	for (i=0; i< count;i++)
	{
	fprintf(fp_out,"%d ",path[i]);
	}
	fprintf(fp_out,"\n");

}

/* DV abstract version that hides implementation by removing the parent array from the parameter list */
/* leaving only parameters that can be passed as arguments from the application code                  */

/*bool find_path(graph *g, int start, int end) {// things to do find the minimum weight of the paths
	bool is_path;
	

	if (debug) printf("Path from %d to %d:\n",start,end);

	if ((start < 1) || (start > g->nvertices)) {
		if (debug) 
			printf("Invalid start vertex\n");
		is_path = false;
	}
	else if ((end < 1) || (end > g->nvertices)) {
		if (debug) 
			printf("Invalid end vertex\n");
		is_path = false;
	}
	else {
		initialize_search(g);
		bfs(g, start);
		is_path = find_path(start, end, parent,min_weight,fp_out); // now call the version of find_path that has the parent array as an argument
		if (debug) printf("\n");
	}
	return(is_path);
}*/

bool find_path1(graph *g, int start, int end, queue1 q, FILE *fp_out) {// things to do find the minimum weight of the paths
	bool is_path;
	printf("value %d\n",get);

	if (debug) printf("Path from %d to %d:\n",start,end);

	if ((start < 1) || (start > g->nvertices)) {
		if (debug) 
			printf("Invalid start vertex\n");
		is_path = false;
	}
	else if ((end < 1) || (end > g->nvertices)) {
		if (debug) 
			printf("Invalid end vertex\n");
		is_path = false;
	}
	else {
		initialize_search(g);

		printf("i am out\n");
		//parent[var.y_vals] =par;
		bfs(g, start);
		is_path = find_path(start, end, parent,min_weight,fp_out); // now call the version of find_path that has the parent array as an argument
		if (debug) printf("\n");
	}
	return(is_path);
}

int output()
{
	//printf("minweight: %d\n",minweight);
	return(get);
}


void numOfTrips(int tourists,int seats, FILE *fp_out)
{
	int var = 0, val=seats-1, s=tourists;
	var =tourists/(seats-1);
	if (tourists%(seats-1) == 0)
	{
		printf("Minimum Number of Trips = %d: ",var);
		fprintf(fp_out,"Minimum Number of Trips = %d: ",var);
	}
	else
	{
		printf("Minimum Number of Trips = %d: ",var+1);
		fprintf(fp_out,"Minimum Number of Trips = %d: ",(var)+1);
	}

	while(true)
	{

		if(s<= (seats-1))
		{
			printf("%d ", s);
			fprintf(fp_out,"%d ", s);
			break;
		}
		else
		{
			printf("%d ", seats-1);
			fprintf(fp_out,"%d ", seats-1);
		}
		s = s - val;

	}
	printf("\n");
	fprintf(fp_out,"\n");
}

void flag_edge(graph * g, int x, int y, bool directed)
{

	edgenode * e = g->edges[x];
	while (e!=NULL)
	{
		if (e->y==y)
			e->weight=-1;
		e= e->next;	
	}
	if(!directed)
	{
		flag_edge(g,y,x,true);
	}
}

/*	queue

Implementation of a FIFO queue abstract data type.

by: Steven Skiena
begun: March 27, 2002
*/


/*
Copyright 2003 by Steven S. Skiena; all rights reserved. 

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/

void init_queue(queue *q)
{
	q->first = 0;
	q->last = QUEUESIZE-1;
	q->count = 0;
}
void init_queue1(queue1 *q)
{
	q->first = 0;
	q->last = QUEUESIZE-1;
	q->count = 0;
}

void enqueue(queue *q, item_type x)
{
	if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n",x);
	else {
		q->last = (q->last+1) % QUEUESIZE;
		q->q[ q->last ] = x;    
		q->count = q->count + 1;
	}
}
void enqueue1(queue1 *q, vals x)
{
	if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n",x);
	else {
		q->last = (q->last+1) % QUEUESIZE;
		q->q[ q->last ] = x;    
		q->count = q->count + 1;
	}
}
item_type dequeue(queue *q)
{
	item_type x;

	if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
	else {
		x = q->q[ q->first ];
		q->first = (q->first+1) % QUEUESIZE;
		q->count = q->count - 1;
	}

	return(x);
}

vals dequeue1(queue1 *q)
{
	vals x;

	if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
	else {
		x = q->q[ q->first ];
		q->first = (q->first+1) % QUEUESIZE;
		q->count = q->count - 1;
	}

	return(x);
}
item_type headq(queue *q)
{
	return( q->q[ q->first ] );
}

int empty_queue(queue *q)
{
	if (q->count <= 0) return (TRUE);
	else return (FALSE);
}
int empty_queue1(queue1 *q)
{
	if (q->count <= 0) return (TRUE);
	else return (FALSE);
}


void print_queue(queue *q)
{
	int i;

	i=q->first; 

	while (i != q->last) {
		printf("%d ",q->q[i]);
		i = (i+1) % QUEUESIZE;
	}

	printf("%2d ",q->q[i]);
	printf("\n");
}

void print_queue1(queue1 *q)
{
	int i;

	i=q->first; 

	while (i != q->last) {
		//printf("%d\n ",q->q[i]);
		printf("\n");

		printf("%d- ",q->q[i].x_val);
		printf("%d- ",q->q[i].y_vals);
		printf("%d ",q->q[i].weights);
		i = (i+1) % QUEUESIZE;
	}

	printf("%2d ",q->q[i]);
	printf("\n");
}


/*void prompt_and_exit(int status) {
printf("Press any key to continue and close terminal\n");
getchar();
getchar();
exit(status);
}*/

