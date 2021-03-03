#include<bits/stdc++.h> 
using namespace std; 


void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 


void printGraph(vector<int> adj[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		cout << "\n Adjacency list of vertex "
			<< i << "\n head "; 
		for (auto x : adj[i]) 
		cout << "-> " << x; 
		printf("\n"); 
	} 
} 

int main() 
{ 
	int n; 
    cin>>n;
	vector<int> adj[n]; 
	for(int i=0;i<n;i++){
        int l,temp;
        cin>>l;
        for(int j=0;j<l;j++){
            cin>>temp;
            addEdge(adj,i,temp);
        }
    }
	printGraph(adj, n); 
	return 0; 
} 
