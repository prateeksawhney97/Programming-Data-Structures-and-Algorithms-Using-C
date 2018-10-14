#include <cstdio>
#include <stdlib.h>
#include <limits.h>
// function prints MST as vertex i - vertex j w , in order of vertex j (1 to n-1)
int printMST(int parent[], int n, int** graph)
{
   for (int i = 1; i <  n; i++)
   printf("%d -- %d %d\n", parent[i], i, graph[i][parent[i]]);
}
int* prim(int** graph,int no_of_vertices);
int main(){
  int no_of_vertices;
 scanf("%d", &no_of_vertices); 
  int** graph = new int*[no_of_vertices];
  for(int i = 0; i < no_of_vertices; ++i)
     graph[i] = new int[no_of_vertices];
  for(int i = 0; i <no_of_vertices; ++i)
    for(int j = 0; j < no_of_vertices; ++j)
      scanf("%d",&graph[i][j]);
 
   
  int* parent;
   parent= prim(graph,no_of_vertices);
    // Print the solution
   printMST(parent, no_of_vertices, graph);
     return 0;
}

int minKey(int key[], bool mstSet[],int no_of_vertices)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < no_of_vertices; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
int* prim(int** graph,int no_of_vertices)
{
     int* parent= (int*)malloc(sizeof(int)*no_of_vertices); 
     int key[no_of_vertices];  
     bool mstSet[no_of_vertices];   

     for (int i = 0; i < no_of_vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     
     parent[0] = -1; 
     for (int count = 0; count < no_of_vertices-1; count++)
     {
         int u = minKey(key, mstSet, no_of_vertices);
         mstSet[u] = true;
         for (int v = 0; v < no_of_vertices; v++)
              if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
  return parent;
   }
