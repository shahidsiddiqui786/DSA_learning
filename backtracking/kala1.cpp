#include<bits/stdc++.h>
using namespace std;


int minDistance(int dist[], bool sptSet[],int V) 
{ 
    
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
void printSolution(int dist[],int V) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
}   

  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[][15], int src, int V, unordered_map<char, int> umap) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i
    vector<int> arr;
  
    bool sptSet[V]; 

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0;
    
  
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet,V); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true;
         arr.push_back(u);
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                      
                }
        }   
                
    } 
  
    // print the constructed distance array 
    for(int i=0;i<V;i++){
        cout<<arr[i]<<" ";
    }
    printSolution(dist,V); 
}


int main() 
{ 
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int graph[15][15] = {-1};
        char topper;
         char ch1,ch2,ch3;
        unordered_map<char, int> umap;
        cin>>topper;
        umap[topper] = 0;
        for(int i=0;i<(n-1);i++){
            cin>>ch1;
            umap[ch1] = (i+1);
        }

        int e,val;
        cin>>e; 
        for(int i=0;i<e;i++){
            cin>>ch2>>ch3>>val;
            graph[umap[ch2]][umap[ch3]] = val;
            graph[umap[ch3]][umap[ch2]] = val;
        }
        
        dijkstra(graph,0,n,umap);
    }

	return 0; 
} 
