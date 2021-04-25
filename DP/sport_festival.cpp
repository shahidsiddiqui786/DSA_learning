#include<bits/stdc++.h>
using namespace std;
typedef double dl;
#define MOD 1000000007
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//problem : given array[], u need to  minimize the exp ,
// summation(max(a1,a2,..ai) - min(a1,a2,...ai)) from 1 to n





void solve(){
    int n;
	cin>>n;
	ll arr[n+1], dp[n+1][n+1];
	for (int i = 0; i < n; ++i) {
		cin>>arr[i];
		dp[i][i] = 0;
	}
	sort(arr, arr+n);
	for (int it = 1; it < n; ++it) { 
		int i = 0;
		for (int j = it; j < n; ++j,++i) {
			dp[i][j] = arr[j] - arr[i];
			if (i+1 < n && (dp[i+1][j] < dp[i][j-1])) {
				dp[i][j] += dp[i+1][j];
			} else {
				dp[i][j] += dp[i][j-1];
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}

int main() {
    io
    solve();
}