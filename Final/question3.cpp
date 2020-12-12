#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>
#include<climits>
using namespace std;
#define V 9
#define T 6
//3.1
int minDistance(int dist[], bool sptSet[])  //helper function for dijkstra()
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 

void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
void dijkstra(int graph[V][V], int src) //given to students in slides by Professor Kostas Alexis
{
    int dist[V]; 
  
    bool sptSet[V]; 
  
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    
    dist[src] = 0; 
  
    
    for (int count = 0; count < V - 1; count++) { 
        
        int u = minDistance(dist, sptSet); 
  
        
        sptSet[u] = true; 
  
        
        for (int v = 0; v < V; v++) 
  
           
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
    
    printSolution(dist); 
} 

//3.2
int minKey(int key[], bool mstSet[])  
{  
    
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < T; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  
void printMST(int parent[], int graph[T][T])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < T; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
  

void primMST(int graph[T][T])  
{  
    
    int parent[T];  
      
    
    int key[T];  
      
   
    bool mstSet[T];  
  
    
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    
    key[0] = 0;  
    parent[0] = -1; 
  
     
    for (int count = 0; count < V - 1; count++) 
    {  
        
        int u = minKey(key, mstSet);  
  
        
        mstSet[u] = true;  
  
        
        for (int v = 0; v < V; v++)  
  
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    
    printMST(parent, graph);  
}  

int main() { /* Let us create the example graph discussed above */
cout<<"For 3.1 (Dijkstra's): "<<endl;
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                {0, 8, 0, 7, 0, 4, 0, 0, 2},  
                {0, 0, 7, 0, 9, 14, 0, 0, 0},   
                {0, 0, 0, 9, 0, 10, 0, 0, 0},   
                {0, 0, 4, 14, 10, 0, 2, 0, 0},        
                {0, 0, 0, 0, 0, 2, 0, 1, 6},          
                {8, 11, 0, 0, 0, 0, 1, 0, 7},        
                {0, 0, 2, 0, 0, 0, 6, 7, 0}        
                };   
  dijkstra(graph, 0);    

int graph2[T][T] = {{0, 10, 20, 0, 0, 0},
                {10, 0, 0, 50, 10, 0}, 
                {20, 0, 0, 20, 33, 0},  
                {0, 50, 20, 0, 20, 2},   
                {0, 10, 33, 20, 0, 1},   
                {0, 0, 0, 2, 1, 0},        
                };

    primMST(graph2);
  return 0; 
  } 

  /* The MST solution for the graph provided is 43, when you compile and run the code */