#ifndef _GRAPH_H_
#define _GRAPH_H_

/* basic directed graph type */
typedef struct graph *Graph;


/* create a new graph with n vertices labeled 0..n-1 */
Graph graphCreate(int n);

/* free all space used by graph */
void graphDestroy(Graph);


/* an egde to an existing graph */
/* doing this more than once may have unpredictable */
void graphAddEdge(Graph, int source, int sink);

/* return number if vertices/edges in the graph */
int graphVertexCount(Graph);
int graphEdgeCount(Graph);


/* invoke f on akk edges (u,v) with source u*/
/* supplying data as final parameter to f */
/* no particular order is guaranteed*/
void graphForeach(Graph g, int source,
		  void (*f)(Graph g, int source, int sink, void *data),
		  void *data);


#endif
