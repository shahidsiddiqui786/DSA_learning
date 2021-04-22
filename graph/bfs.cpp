#include<bits/stdc++.h>
using namespace std;
#define NIL -1

int n,m;
int vtx[20][20];
int mintx[20][20];
int minDiffculty = INT_MAX;
bool flag = false;
int timer;
vector<bool> visited;
vector<int> enterTime, lowTime;


void calculateDiffculty(int a[20][20]){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(a[i][j]!=0){
            ans += a[i][j];
          }
        }
    }
    ans = ans/2;
    if(ans < minDiffculty){
        minDiffculty = ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mintx[i][j] = a[i][j];
            }
        }
    }
}


void dfs(int a[20][20],int v,int parent) {
    visited[v] = true;
    enterTime[v] = lowTime[v] = timer++;
    for (int i=0;i<n;i++) {
        if(a[i][v]!=0){
            if (i == parent){
                continue;
            } 
            if (visited[i]) {
                lowTime[v] = min(lowTime[v], enterTime[i]);
            } 
            else {
                dfs(a,i, v);
                lowTime[v] = min(lowTime[v], lowTime[i]);
                if (lowTime[i] > enterTime[v]){
                  flag = true;
                  return;
                }
            }
        }
    }
}

bool isbridges(int a[20][20]) {
  flag = false;
    timer = 0;
    visited.assign(n, false);
    enterTime.assign(n, -1);
    lowTime.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (!visited[i]){
            dfs(a,i,NIL);
        }
    }
    return flag;
}


bool allNodesincluded(vector<bool> st){
    for(int i=0;i<n;++i){
      if(!st[i])
      return false;
    }
    return true;
}


void allConfig(int a[][20],int s,vector<bool>v){
  if(!v[s])
  v[s] = true;
  if(allNodesincluded(v)){
    //check bridge in a
    if(!isbridges(a)){
      calculateDiffculty(a);
    }
  }
  for(int i=0;i<n;++i){
    if(a[s][i] == 0 && vtx[s][i]!=0){
      a[s][i] = vtx[s][i];
      a[i][s] = vtx[s][i];
      allConfig(a,i,v);
      a[s][i] = 0;
      a[i][s] = 0;
    }
  }
}

void solution(){
  int b[20][20];
  for(int i=0;i<20;++i)
  for(int j=0;j<20;++j)
  b[i][j]= 0;
  
  for(int i=0;i<n;++i){
    vector<bool>visi(n,false);
    allConfig(b,i,visi);
  }
}


int main() {
     
     int t;
     cin>>t;
     while(t--){
        int a,b,c;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vtx[i][j] = 0;
            }
        }
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            vtx[a][b] = c;
            vtx[b][a] = c;
        }
        minDiffculty = INT_MAX;
        solution();
        if(minDiffculty == INT_MAX){
            cout<<"NIL"<<'\n';
        }
        else{
            cout<<minDiffculty<<'\n';
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i < j && mintx[i][j]!=0){
                    cout<<i<<" "<<j<<'\n';
                    }
                }
            }
        } 
     }
}
