#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;


template<typename T>

class Graph {

    map<T, list<T> > adjList;

    public:
       Graph() {

       }
       void addEdge(T u, T v, bool bidir = true){
           adjList[u].push_back(v);
           if(bidir){
               adjList[v].push_back(u);
           }
       }

       void print(){

           //iterate over the map
           for(auto i : adjList){
               cout<<i.first<<"->";
               for(T node : i.second){
                   cout<<node<<" ";
               }
               cout<<'\n';
           }
       }

       void bfs(T src){

           queue<T> q;
           map<T,bool> visited;

           q.push(src);
           visited[src] = true;

           while(!q.empty()){

               T node = q.front();
               cout<<node<<" ";
               q.pop();
               // search neighbours
               for(int neighbour : adjList[node]){
                   if(!visited[neighbour]){
                       q.push(neighbour);
                       visited[neighbour] = true;
                   }
               }
           }
       }

        void shortestPath(T src){

           queue<T> q;
           map<T,int> dist;
           map<T,T> parent;

           for(auto i : adjList){
               dist[i.first] = INT_MAX;
           }

           q.push(src);
           dist[src] = 0;
           parent[src] = src;

           while(!q.empty()){

               T node = q.front();
            //    cout<<node<<" ";
               q.pop();
               // search neighbours
               for(int neighbour : adjList[node]){
                   if(dist[neighbour] == INT_MAX){
                       q.push(neighbour);
                       dist[neighbour] = dist[node]+1; 
                       parent[neighbour] = node;
                   }
               }
           }
 
           //print distances
           for(auto i:adjList){
               T node = i.first;
               cout<<"Dist of "<<node<<"from "<<src<<"is "<<dist[node]<<'\n';
           }
       }

       int dfsHelper(T node, map<T,bool> &visited){
           //reach this node so marked true
           visited[node] = true;
           //try to find out unvisited neighbours
           for(T neighbour : adjList[node]){
               if(!visited[neighbour]){
                   dfsHelper(neighbour,visited);
               }
           }
           
       }

       void dfs(T src){
           map<T, bool> visited;
           dfsHelper(src,visited); 
           // for more than one compnents
           cout<<'\n';
           int component = 1;
           for(auto i : adjList){
               T node = i.first;
               if(!visited[node]){
                   dfsHelper(node,visited);
                   component++;
                   cout<<'\n';
               }
           }
           cout<<"comonents are "<<component<<'\n';
       }

       void dfsHelperSort(T node, map<T,bool> &visited, list<T> &ordering){

            visited[node] = true;

            //will call dfs on unvisited neigboughring
            for(T neighbour:adjList[node]){
                if(!visited[neighbour]){
                    dfsHelperSort(neighbour,visited,ordering);
                }
            }
            //all child visited
            ordering.push_front(node);
       }

       void dfsTopologicalSort(){
             map<T,bool> visited;
             list<T> ordering;

             for(auto i:adjList){
                 T node = i.first;
                 if(!visited[node]){
                     dfsHelperSort(node,visited,ordering);
                 }
             }

             //print sort
             for(T element:ordering){
                 cout<<element<<"--->";
             }
       }

       void bfsTopologicalSort(){
           queue<T> q;
           map<T,bool> visited;
           map<T,int> indegree;

           for(auto i:adjList){
               //i is a pair of node and its neigbour
               T node = i.first;
               visited[node] = false;
               indegree[node] = 0;
           }

           //init the indegrees of all nodes
           for(auto i:adjList){
               T u = i.first;
               for(T v : adjList[u]){
                   indegree[v]++;
               }
           }

           //find out all nodes with 0 indegree
           for(auto i:adjList){
               T node = i.first;
               if(indegree[node] == 0){
                   q.push(node);
               }
           }

           while(!q.empty()){
               T node = q.front();
               q.pop();
               cout<<node<<"->";

               for(T neigbour:adjList[node]){
                    indegree[neigbour]--;

                    if(indegree[neigbour] == 0){
                        q.push(neigbour);
                    }
               }
           }
       }

       bool iscyclicBFS(T src){
            queue<T> q;
            map<T,bool> visited;
            map<T,T> parent;

            q.push(src);
            visited[src] = true;
            parent[src] = src;

            while(!q.empty()){
                T node = q.front();
                q.pop();

                for(T neigbour:adjList[node]){
                    if(visited[neigbour] && parent[node] != neigbour){
                        return true;
                    }
                    else if(!visited[neigbour]){
                        visited[neigbour] = true;
                        parent[neigbour] = node;
                        q.push(neigbour);
                    }
                }
            }
            return false;
       }

       bool iscyclicHelper(T node,map<T,bool> &visited, map<T,bool> &instack){
              visited[node] = true;
              instack[node] = true;

              //explore neigboures
              for(T neighbour:adjList[node]){
                  //Two things 
                  //current node is not visited
                  //but its furhur branch may lead to cycle
                  if(!visited[neighbour] && iscyclicHelper(neighbour,visited,instack) || instack[neighbour]){
                      return true;
                  }
              }
              //pop the current node from stack
              instack[node] = false;
              return false;
       }

       bool isContainBackEdgeDFS(){
           map<T,bool> visited;
           map<T,bool> instack;

           //to check for cycle in each dfs
           for(auto i:adjList){
               T node = i.first;
               if(!visited[node]){
                   bool cycle = iscyclicHelper(node,visited,instack);
                   if(cycle){
                       return true;
                   }
               }
           }
           return false;
       }
};


int main(){
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,3);
    

    // g.print();
    // g.shortestPath(1);
    g.dfs(1);
    // g.dfsTopologicalSort();
    // cout<<'\n';
    // g.bfsTopologicalSort();
    // cout<<g.iscyclicBFS(1)<<" ";

    // Graph<string> g1;
    // g1.addEdge("e","d",false);
    // g1.addEdge("a","d",false);
    // g1.addEdge("d","v",false);
    // g1.addEdge("v","b",false);
    // g1.addEdge("b","g",false);
    // g1.addEdge("g","u",false);
    // // g1.bfsTopologicalSort();
    // // cout<<g1.iscyclicBFS("e")<<" ";

    // // g1.print();

    // Graph<int> g2;
    // g2.addEdge(0,2,false);
    // g2.addEdge(0,1,false);
    // g2.addEdge(2,3,false);
    // g2.addEdge(2,4,false);
    // g2.addEdge(3,0,false);
    // g2.addEdge(4,5,false);
    // g2.addEdge(1,5,false);
    // cout<<"backedge "<<(g2.isContainBackEdgeDFS() ? "present" : "absent")<<" ";
}

