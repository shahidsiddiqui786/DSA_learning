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
 




struct event
{
	string event;
	int start;
	int end;
};

bool comp( struct event a,struct event b)
{
	if(a.start==b.start)
	return a.end < b.end;
	return a.start<b.start;
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		struct event v[n];
		int max_go=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i].event>>v[i].start>>v[i].end;
			max_go=max(max_go,v[i].end);
		}

		sort(v,v+n,comp);

		int minmylevel=0;
		int count=0;
		int j=0;
		int my_max=0;
		
		while(j<n && minmylevel<max_go)
		{
			while(v[j].start<=minmylevel)
			{
				my_max=max(my_max,v[j].end);
				j++;
			}
			minmylevel=my_max;
			count++;
		}

		if(minmylevel==max_go)
		cout<<count<<"\n";
		else
		cout<<"-1\n";

	}
}