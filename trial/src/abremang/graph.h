/* 
  Interface file

  Graph - adjacency list implementation based on code by Steven Skiena:

  Steven S. Skiena, "The Algorithm Design Manual", 2nd Edition, Springer, 2008.

  David Vernon
  19 March 2017

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define QUEUESIZE       1000

typedef int item_type;

typedef struct {
        item_type q[QUEUESIZE+1];       /* body of queue */
        int first;                      /* position of first element */
        int last;                       /* position of last element */
        int count;                      /* number of queue elements */
} queue;


typedef struct  {
	int y_vals;
	int weights;
	int x_val; 
//int y_sorted;

}vals;

typedef struct {
        vals q[QUEUESIZE+1];       /* body of queue */
        int first;                      /* position of first element */
        int last;                       /* position of last element */
        int count;                      /* number of queue elements */
} queue1;

/* Adjacency list representation of a graph of degree MAXV          */
/*                                                                  */
/* Directed edge (x, y) is represented by edgenode y in x’s         */
/* adjacency list. Vertices are numbered 1 .. MAXV                  */

#define MAXV 1000  /* maximum number of vertices */

//Original code
//typedef struct {
//   int y;                        /* adjacent vertex number          */
//   int weight;                   /* edge weight, if any             */
//   struct edgenode *next;        /* next edge in list               */
//} edgenode;

typedef struct edgenode *EDGENODE_PTR;

typedef struct edgenode {
   int y;                        /* adjacent vertex number          */
   int weight;                   /* edge weight, if any             */
   EDGENODE_PTR next;            /* next edge in list               */
} edgenode;

typedef struct {
        edgenode *edges[MAXV+1]; /* adjacency info: list of edges   */
        int degree[MAXV+1];      /* number of edges for each vertex */
        int nvertices;           /* number of vertices in graph     */
        int nedges;              /* number of edges in graph        */
        bool directed;           /* is the graph directed?          */
} graph;


void initialize_graph(graph *g, bool directed);

bool read_graph(graph *g, bool directed);
 
void insert_edge(graph *g, int x, int y, bool directed, int w);

void print_graph(graph *g);

void initialize_search(graph *g);

void bfs(graph *g, int start);

void process_vertex_late(int v);

void process_vertex_early(int v);

void process_edge(int x, int y);

bool find_path(int start, int end, int parents[], int weight[],FILE *fp_out);
bool find_path3(int start, int end, int parents[], int weight[],FILE *fp_out);
bool find_path(graph *g, int start, int end);

void init_queue(queue *q);

void enqueue(queue *q, item_type x);
void enqueue(queue *q, vals x);
item_type dequeue(queue *q);

item_type headq(queue *q);

int empty_queue(queue *q);
int empty_queue1(queue1 *q);

void print_queue(queue *q);
void print_queue1(queue1 *q);
void dfs(graph *g, int v);
int bfs_fire(graph *g, int start);
int output();
void numOfTrips(int tourists,int seats, FILE *fp_out);
int bfs_fire1(graph *g, int start);
void enqueue1(queue1 *q, vals x);
void init_queue1(queue1 *q);
void insertion_sort(queue1 *qA);
vals dequeue1(queue1 *q);
int CC(graph *g);
bool find_path1(graph *g, int start, int end, queue1 q,FILE *fp_out);
bool find_path2(graph *g, int start, int end, queue1 q,FILE *fp_out);
int graphchange(int v, int v1);
void block_edge(graph *g, int y,int x);
void find_vertex(graph *g, int y,int x, bool directed);
void print_path(FILE *fp_out);
void flag_edge(graph * g, int x, int y, bool directed);
//void prompt_and_exit(int status);
 