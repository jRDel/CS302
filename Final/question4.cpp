//implementation provided by Professor with tweaks
#define V 5
#include<iostream>
#include <vector>
#include <climits>
#include  <algorithm>
using namespace std;
int tsp(int graph[][V], int s)
{
    
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    
    int min_path = INT_MAX;
    do {
 
        
        int current_pathweight = 0;
 
        
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

int main()
{
    int start=1;
    int graph[][V] = {{0,10,16,12,8},
                      {10,0,15,0,20},
                      {16,15,0,10,0},
                      {12,0,10,0,8},
                      {8,20,0,8,0}
    };

cout<< tsp(graph, start)<<endl;

return 0;

}

//4.1
/*Also implemented in my main driver in question4.cpp, but for reiteration purpose, the graph is defined here:
int graph[V][V] = {{0,10,16,12,8},
                      {10,0,15,0,20},
                      {16,15,0,10,0},
                      {12,0,10,0,8},
                      {8,20,0,8,0}
    };
*/

//4.2
/*The solution to this problem can be done when you compile my question4.cpp. If you start at vertex 1, denoted by int start=1 which you then pass into the function, the solution you
get is 28.*/