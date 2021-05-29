#include<bits/stdc++.h>
using namespace std;
typedef double dl;
#define MOD 1000000007
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
#define loop1(i, b, n) for (int i = b; i <= n; i++)
#define loopit(a) for (auto it = a.begin(); it != a.end(); it++)
#define ms(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define pi pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vip vector<pair<int,int>>
#define sip set<pair<int,int>>
#define si set<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define test ll t,no=1; cin>>t; while(t--){ solve(no); no++;};
//__________________________________________________________//
 
 
int n, l;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p,vector<int> adj[])
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,adj);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root,vector<int> adj[]) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root,adj);
}


int main(){
    int m,q;
    cin>>n>>m;
    int a,b;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    
    preprocess(1,adj);
    cin>>q;
    int u,v;
    while(q--){
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }

}