#include <bits/stdc++.h>
using namespace std; 

//Note:- Topological Sorting for a graph is not possible if the graph is not a DAG.

class Graph { 

	int V; 
	list<int>* adj; 

	void topologicalSortUtil(int v, bool visited[], 
							stack<int>& Stack); 

public: 
	Graph(int V); 

	void addEdge(int v, int w); 

	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 

void Graph::topologicalSortUtil(int v, bool visited[], 
								stack<int>& Stack) 
{ 

	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 

	Stack.push(v); 
} 


void Graph::topologicalSort() 
{ 
	stack<int> Stack; 

	bool* visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			topologicalSortUtil(i, visited, Stack); 

	while (Stack.empty() == false) { 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
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

	cout << "Following is a Topological Sort of the given "
			"graph \n"; 
	
	g.topologicalSort(); 

	return 0; 
}
