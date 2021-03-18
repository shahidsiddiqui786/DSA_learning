//matrix chain multiplication optimal operation
#include<bits/stdc++.h>
using namespace std;

//Recursive Approach

// int MatrixChainOrder(int p[], int i, int j) 
// { 
// 	if (i == j) 
// 		return 0; 
// 	int k; 
// 	int min = INT_MAX; 
// 	int count; 
// 	for (k = i; k < j; k++) 
// 	{ 
// 		count = MatrixChainOrder(p, i, k) 
// 				+ MatrixChainOrder(p, k + 1, j) 
// 				+ p[i - 1] * p[k] * p[j]; 

// 		if (count < min) 
// 			min = count; 
// 	} 
// 	return min; 
// } 

//memeoization approach
int dp[1000][1000];

int MatrixChainOrder(int p[], int i, int j) 
{ 
	if (i == j) 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 
    if(dp[i][j] != -1) {
		return dp[i][j];
	}

	for (k = i; k < j; k++) 
	{ 
		count = MatrixChainOrder(p, i, k) 
				+ MatrixChainOrder(p, k + 1, j) 
				+ p[i - 1] * p[k] * p[j]; 

		if (count < min) 
			min = count; 
	} 
	return dp[i][j] = min; 
} 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = -1;
		}
	}
    cout<<MatrixChainOrder(arr,1,n-1);
} 

