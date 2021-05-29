#include<bits/stdc++.h>
using namespace std;
//Lowest commmon Ancestor

/* This is basically a efficient algorithm  to calculate lowest commmon ancestor of
   two node.
*/

//naive appproach

/*
    int lca(int a, int b){
        //assuming b is at higher level
        int diff = level[a] - level[b]  //find level of node using dfs

        while(diff > 0){
            b = par[a];
            diff--;
        }

        if(a == b) return a;

        while(par[a]!=par[b]){
            a = par[a];
            b = par[b];
            return par[a];
        }
    }
*/

//LCA using sparse table / 2D DP

/* In this method the precomputation step would consist of calculating the 2ith ancestor for all valid i
   for each node.
   To do this we would be using a sparse table. This technique to find the kth ancestor for a node in a tree
   is also known as binary raise technique. We would be precomputing a 2D table P such that P[i][j] stores the
   2jth ancestor for node i.
*/

//P[i][j] stores the 2^jth ancestor of node i
int MAXLOG; 

vector<vector<int>> P;
vector<int> parent;
vector<int> level;

void dfs(int u,int cur_level,vector<int> adj[]){
    level[u] = cur_level;

    for(int child : adj[u]){
        if(level[child] == -1){
            parent[child] = u;
            dfs(child,cur_level+1,adj);
        }
    }
    return ;
}

void computeLevel(int root, vector<int> adj[]) {
    parent[root] = root;
    dfs(root,1,adj);
}

void preprocess(int N, vector<int> adj[]){
    //Every element in P[][] is -1 initially;
    MAXLOG = log2(N);
    P.assign(N,vector<int>(MAXLOG,-1));
    parent.resize(N);
    level.resize(N,-1);
    
    computeLevel(1,adj);
    //The first ancestor(2^0 th ancestor)
    //for every node is parent[node]
    for(int i = 1 ; i < N ; ++i){
        P[i][0] = parent[i] ; 
    }

    for(int j = 1; (1<<j) < N ; ++j){
        for(int i = 1 ; i < N ; ++i){
            //If a node does not have a (2^(j-1))th ancestor
            //Then it does not have a (2^j)th ancestor
            //and hence P[i][j] should remain -1
            //Else the (2^j)th ancestor of node i
            //is the (2^(j-1))th ancestor of ((2^(j-1))th ancestor of node i)
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1] ; 
            }
        }
    }
} 


int lca(int u , int v,int N){
    if(level[u] < level[v]){
        swap(u,v) ;     
    }
    //u is the node at a greater depth/lower level
    //So we have to raise u to be at the same
    //level as v. 
    int dist = level[u] - level[v] ; 
    while(dist > 0){
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ; 
    }

    if(u == v){
        return u ; 
    }

    //Now we keep raising the two nodes by equal amount
    //Untill each node has been raised uptill its (k-1)th ancestor
    //Such that the (k)th ancestor is the lca. 
    //So to get the lca we just return the parent of (k-1)th ancestor 
    //of each node
    

    for(int j = MAXLOG ; j >= 0 ; --j){
        //Checking P[u][j] != P[v][j] because if P[u][j] == P[v][j]
        //P[u][j] would be the Lth ancestor such that (L >= k) 
        //where kth ancestor is the LCA
        //But we want the (k-1)th ancestor. 
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ; 
            v = P[v][j] ; 
        }
    }
    return parent[u] ; //or parent[v]
}   

int main(){
    int n,m,q;
    cin>>n>>m;
    int size = n+1;
    vector<int> adj[size];
    int a,b;
    
    for(int i=0;i<m;i++){
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    
    preprocess(n+1,adj);
    cin>>q;
    int u,v;
    while(q--){
        cin>>u>>v;
        cout<<lca(u,v,n)<<'\n';
    }

}