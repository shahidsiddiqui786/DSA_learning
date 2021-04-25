#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int V; 
	list<int> *adj; 
public:
	Graph(int V);

	void addEdge(int v, int w); 

	void BFS(int s); 
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

void Graph::BFS(int s)
{

	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		
		s = queue.front();
		cout << s << " ";
		queue.pop_front();


		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
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
    int s;
    cout<<"enter node no from which u want bfs\n";
    cin>>s;
    g.BFS(s);
	return 0;
}
