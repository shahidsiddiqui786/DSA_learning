#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
     unordered_map<T, list<pair<T,int > > > adjList;

    public:
       void addEdge(T u, T v, int dist, bool bid=true) {
               adjList[u].push_back(make_pair(v,dist));
               if(bid){
                  adjList[v].push_back(make_pair(u,dist)); 
               }
       }

       void print(){
           for(auto i:adjList){
               cout<<i.first<<"->";

               for(auto node:i.second){
                   cout<<node.first<<" , ";
               }
               cout<<'\n';
           }
       }

       void dijastra(T src){
          unordered_map<T,int> dist;

          //init all distances to inf
          for(auto i:adjList){
              dist[i.first] = INT_MAX;
          }

          set<pair<int,T>> s;

          dist[src] = 0;
          s.insert(make_pair(0,src));

          while(!s.empty()){
              //take out min pair
              auto p = *(s.begin());
              T node  = p.second;
              
              int nodeDist = p.first;
              s.erase(s.begin());

              for(auto child:adjList[node]){
                  if(nodeDist + child.second < dist[child.first]){
                     //as updation in set is not possible
                     //so need to remove old
                     //and add new data
                     T dest = child.first;
                     auto f = s.find(make_pair(dist[dest],dest));
                     if(f!=s.end()){
                         s.erase(f);
                     }
                     dist[dest] = nodeDist+child.second;
                     s.insert(make_pair(dist[dest],dest));
                  }
              }
          }

          for(auto d:dist){
              cout<<d.first<<" is located at distance of "<<d.second<<'\n';
          }
       }
};


int main() {
     
     Graph<int> g;
     g.addEdge(1,2,1);
     g.addEdge(1,3,4);
     g.addEdge(2,3,1);
     g.addEdge(3,4,2);
     g.addEdge(1,4,7);

     g.dijastra(1);
}