#include<stdio.h>
#include<stdlib.h>

struct Edge
{
	int src;
	int dest;
	int w;
};

struct Graph
{
	int V;
	int E;
	struct Edge* edges;
};

struct Graph* create(int v,int e)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));	
	graph->V = v;
	graph->E = e;
	graph->edges = (struct Edge*)malloc(e*sizeof(struct Edge));
	return graph;
}

void negativecycle(struct Graph* graph,int s)
{
	int v,e;
	v=graph->V;
	e = graph->E;
	int flag = -1;
	int A[v];
	int max = 10000;
	for(int i=0;i<v;i++){
		A[i] = max;
	}
	
	A[s] = 0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int x = graph->edges[j].src;
			int y = graph->edges[j].dest;
			if( A[x]!=max && (A[y] > ( graph->edges[j].w + A[x] ) )){A[y] = graph->edges[j].w + A[x];}
		}
	}
	for(int i=0;i<e;i++){
		int x = graph->edges[i].src;
		int y = graph->edges[i].dest;
		if(A[x] != max && (A[y] > (graph->edges[i].w + A[x]) ) ){flag = 1;}
	}
	printf("%d\n",flag);
}


int main()
{
	int v,e,x,y,w;
	scanf("%d %d",&v,&e);
	if(e<=(v*(v-1))){
	struct Graph* graph = create(v,e);
	
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		graph->edges[i].src = x;
		graph->edges[i].dest = y;
		graph->edges[i].w = w;
	}
	negativecycle(graph,0);
	}
}




