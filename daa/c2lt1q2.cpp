#include<bits/stdc++.h>
using namespace std;

int studtNetwork[15][15];
vector<pair<int,int>> minEdges;
vector<pair<int,int>> edges;
int minDiffculty;

void calMinDiffPath(int currPos,int n, int getsol, int diffculty,vector<bool>& visited,vector<int> &parent)
{   

    //if traversed all students and get a path from last to init students
	if (getsol == n && studtNetwork[currPos][0] != -1) {
        //then check for total diffculty 
		if(minDiffculty > (diffculty + studtNetwork[currPos][0]) ){
            minDiffculty = (diffculty + studtNetwork[currPos][0]);
            minEdges.clear();
            for(int i=0;i<edges.size();i++){
                minEdges.push_back(edges[i]);
            }
            minEdges.push_back(make_pair(currPos,0));
        }
		return;
	}
    
    //if we are in b/w consider all those connected students
	for (int i = 0; i < n; i++) {
        // who don't get already solution
		if ((!visited[i] )&& studtNetwork[currPos][i] != -1) {

            //mark current student as get
			visited[i] = true;
            parent[i] = currPos;
            edges.push_back(make_pair(currPos,i));

            //again calculate through this path
			calMinDiffPath(i, n, (getsol + 1),(diffculty + studtNetwork[currPos][i]),visited,parent);
            
            //then backtrack to consider other possibility
            edges.pop_back();
            parent[i] = -1;
			visited[i] = false;
		}
        else if((visited[i] && studtNetwork[currPos][i] != -1) && parent[i] == currPos){
             
          
            edges.push_back(make_pair(currPos,i));

            //again calculate through this path
			calMinDiffPath(i, n, (getsol),(diffculty + studtNetwork[currPos][i]),visited,parent);
            
            //then backtrack to consider other possibility
            edges.pop_back();
           
			
        }
	}
    return ;
}

void printPath(){
        //print all valid minEdgess 
        int a,b;
        for(int i=0;i<minEdges.size();i++){
            if(minEdges[i].first > minEdges[i].second){
                swap(minEdges[i].first , minEdges[i].second);
            }   
        }

        sort(minEdges.begin(),minEdges.end());
        for(int i=0;i<minEdges.size();i++){
            cout<<minEdges[i].first<<" "<<minEdges[i].second<<'\n';
        }
        return ;
}

void solveProblem(int n){
        
        vector<bool> visited(n);
        vector<int> parent(n);
        edges.clear(); 
        for (int i = 0; i < n; i++){
             visited[i] = false;
             parent[i] = -1;
        }

        //init from 0th student 
        visited[0] = true;
        parent[0] = 0;
        minDiffculty = INT_MAX;

        //call for function to find min path from init student to init
        calMinDiffPath(0, n, 1, 0,visited,parent);

        if(minDiffculty == INT_MAX){
            // there is no valid path such that we can make copy
            //to every student
            cout<<"NIL"<<'\n';
            return ;
        }
        else{
            //min diffcult path
            cout<<minDiffculty<<'\n';
            printPath();
            return ;
        }
}


int main(){

     int t;
     cin>>t;
     while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                studtNetwork[i][j] = -1;
            }
        }
        int a,b,c;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            studtNetwork[a][b] = c;
            studtNetwork[b][a] = c;
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<studtNetwork[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }

        solveProblem(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cout<<studtNetwork[i][j]<<" ";
            }
            cout<<'\n';
        }
     }
      
}