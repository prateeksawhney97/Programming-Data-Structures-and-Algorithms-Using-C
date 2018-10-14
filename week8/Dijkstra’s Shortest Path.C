#include <cstdio>
#include <stdlib.h>
const int MAXval=1000;


void printSolution(int dist[], int n){
//A function to print the constructed distance array
    for (int i = 0; i < n; i++)
      printf("%d %d\n",i,dist[i]);
}
int* shortestDist(int** graph, int src, int no_of_vertices);

int main()
{
  int no_of_vertices;
  scanf("%d", &no_of_vertices);
  int sourcevertex;
  scanf("%d", &sourcevertex);
  int** graph = new int*[no_of_vertices];
  for(int i = 0; i < no_of_vertices; ++i)
     graph[i] = new int[no_of_vertices];
  for(int i = 0; i <no_of_vertices; ++i)
    for(int j = 0; j < no_of_vertices; ++j)
      scanf("%d", &graph[i][j]);
    
  int* dist=shortestDist(graph, sourcevertex,no_of_vertices);
 // print the constructed distance array
  printSolution(dist, no_of_vertices);
 
    return 0;
}
int minDistance(int dist[], bool sptSet[],int no_of_vertices)
{
   // Initialize min value
   int min = MAXval, min_index;
 
   for (int v = 0; v < no_of_vertices; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
int* shortestDist(int** graph, int src, int no_of_vertices)
{
     int* dist=(int*)malloc(sizeof(int)*no_of_vertices); 
/// Code to compute shortest distance :
bool sptSet[no_of_vertices]; // sptSet[i] will true if vertex i is included in shortest

     // Initialize all distances as INFINITE 
     for (int i = 0; i < no_of_vertices; i++)
        dist[i] = MAXval, sptSet[i] = false;
       dist[src] = 0;
 
     // Find shortest path for all vertices
     for (int count = 0; count < no_of_vertices-1; count++)
     {
            int u = minDistance(dist, sptSet,no_of_vertices);
             sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < no_of_vertices; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != MAXval
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

return dist;
}
