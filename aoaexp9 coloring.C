#include <stdio.h>
#include<conio.h>
#define MAX_VERTICES 100
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int V)
{
int i;
 for (i = 0; i < V; i++) {
if (graph[vertex][i] == 1 && color[i] == c)
{
 return 0;
}
 }
 return 1;
}
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int V, int m)
{
int c;
if (vertex == V)
{
return 1;
 }
 for ( c = 1; c <= m; c++)
 {
if (isSafe(graph, color, vertex, c, V))
{
 color[vertex] = c;
if (graphColoringUtil(graph, color, vertex + 1, V, m))
 {
return 1;
 }
 color[vertex] = 0;
}
 }
 return 0;
 }
int graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int V, int m)
{
 int color[MAX_VERTICES] = {0},i;
 if (graphColoringUtil(graph, color, 0, V, m) == 0)
{
printf("Solution does not exist\n");
return 0;
 }
 printf("Solution exists: Following are the assigned colors\n");
 for ( i = 0; i < V; i++)
{
printf("Vertex %d -> Color %d\n", i + 1, color[i]);
 }
 return 1;
}
void main()
{
 int V, E, m,i;
 int graph[MAX_VERTICES][MAX_VERTICES] = {0};
 clrscr();
 printf("Enter number of vertices: ");
 scanf("%d", &V);
 printf("Enter number of edges: ");
 scanf("%d", &E);
 printf("Enter the edges (in the format u v):\n");
 for (i = 0; i < E; i++)
 {
int u, v;
scanf("%d %d", &u, &v);
graph[u - 1][v - 1] = 1;
graph[v - 1][u - 1] = 1;
 }
 printf("Enter the number of colors to use: ");
 scanf("%d", &m);
 graphColoring(graph, V, m);
 getch();
}