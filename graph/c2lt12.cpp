#include<bits/stdc++.h>
using namespace std;

int ghf[15][15];
vector<pair<int,int>> edge;


void dfdsdf(vector<bool>& v, int currPos,
		int n, int count, int cost, int& ans,vector<pair<int,int>> &trial)
{


	if (count == n && ghf[currPos][0] != -1) {
		if(ans > (cost + ghf[currPos][0]) ){
            ans = (cost + ghf[currPos][0]);
            edge.clear();
            for(int i=0;i<trial.size();i++){
                edge.push_back(trial[i]);
            }
        }
		return;
	}


	for (int i = 0; i < n; i++) {
		if (!v[i] && ghf[currPos][i] != -1) {


			v[i] = true;
            trial.push_back(make_pair(currPos,i));
			dfdsdf(v, i, n, count + 1,
				cost + ghf[currPos][i], ans,trial);

            trial.pop_back();
			v[i] = false;
		}
	}
};


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ghf[i][j] = -1;
        }
    }
    int a,b,c;
    for(int i=0;i<m;i++){
       cin>>a>>b>>c;
       ghf[a][b] = c;
       ghf[b][a] = c;
    }

	vector<bool> v(n);
	for (int i = 0; i < n; i++)
		v[i] = false;


    vector<pair<int,int>> trial;
	v[0] = true;
	int ans = INT_MAX;

	dfdsdf(v, 0, n, 1, 0, ans,trial);


	if(ans == INT_MAX){
        cout<<"NIL"<<'\n';
    }
    else{
        cout<<ans<<'\n';
        for(int i=0;i<edge.size();i++){
            a = edge[i].first;
            b = edge[i].second;
            a > b ? cout<<b<<" "<<a<<'\n' : cout<<a<<" "<<b<<'\n' ; 
            
        }
    }

	return 0;
}
