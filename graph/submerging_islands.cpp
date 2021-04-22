#include<bits/stdc++.h>
using namespace std;


int n; 
map<int,list<int>> adj;
set<int> ans; 

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    // cout<<timer;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                ans.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
       ans.insert(v);
}

void find_cutpoints() {
    timer = 0;
    
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
       
        if (!visited[i])
            dfs (i);
    }
}


int main(){
    int m,a,b;
    cin>>n>>m;
    while(n!=0 && m!=0){
        //init
        
        adj.clear();
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans.clear();
        find_cutpoints();
        cout<<ans.size()<<'\n';
        cin>>n>>m;
    }
}