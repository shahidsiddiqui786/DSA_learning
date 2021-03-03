#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V; 
	list<int>* adj;

	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V); 

	void addEdge(int v, int w);

	void DFS(int v);
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

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
	
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
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
    int s;
    cout<<"enter node no from which u want dfs\n";
    cin>>s;
    g.DFS(s);

	return 0;
}
