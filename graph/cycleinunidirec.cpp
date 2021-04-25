#include<bits/stdc++.h>
using namespace std; 

class Graph 
{ 
	
	int V; 

	list<int> *adj; 
	bool isCyclicUtil(int v, bool visited[], 
							int parent); 
public: 
	
	Graph(int V); 
	
	void addEdge(int v, int w); 
	
	bool isCyclic(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	
	adj[v].push_back(w); 

	adj[w].push_back(v); 
} 


bool Graph::isCyclicUtil(int v, 
				bool visited[], int parent) 
{ 
	
	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != 
					adj[v].end(); ++i) 
	{ 
		
		if (!visited[*i]) 
		{ 
		if (isCyclicUtil(*i, visited, v)) 
			return true; 
		} 

		else if (*i != parent) 
		return true; 
	} 
	return false; 
} 


bool Graph::isCyclic() 
{  
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	for (int u = 0; u < V; u++) 
	{ 
		if (!visited[u]) 
		if (isCyclicUtil(u, visited, -1)) 
			return true; 
	} 
	return false; 
} 


int main() 
{ 
	int n;
    cout<<"enter no of nodes"<<'\n';
    cin>>n;
    Graph g(n);
    for(int i=0;i<n;i++){
        int l;
        cout<<"enter no of node connected to node "<<i<<'\n';
        cin>>l;
        for(int j=0;j<l;j++){
            int tp;
            cin>>tp;
            g.addEdge(i,tp);
        }
    }

    g.isCyclic()?  
       cout << "Graph contains cycle\n": 
       cout << "Graph doesn't contain cycle\n"; 

	return 0; 
} 
