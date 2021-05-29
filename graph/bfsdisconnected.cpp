#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V; 
	list<int> *adj; 
public:
    Graph(int V);
    void addEdge(int v,int w);
    void bfs(int s,vector<bool> &visited);
    void bfsUtil();
};

Graph::Graph(int V)
{
   this->V = V;
   adj = new list<int> [V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bfs(int s,vector<bool> &visited) 
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout<<ele<<" ";
        for(auto child : adj[ele]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

void Graph::bfsUtil()
{
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            bfs(i,visited);
        }
    }
}

int main(){
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
    g.bfsUtil();
	return 0;
}