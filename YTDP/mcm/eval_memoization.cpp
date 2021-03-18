#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];
int parenthesis_count(string s, int i,int j,int isTrue)
{
	if (i > j)
		return false;
	if (i == j) {
		if (isTrue == 1)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}

	if (dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];
	int ans = 0;
	for (int k = i + 1; k <= j - 1; k = k + 2) 
	{
		if (dp[i][k - 1][1] == -1) 
		{
			dp[i][k-1][1] = parenthesis_count(s, i, k - 1, 1);
		} 

		if (dp[k + 1][j][1] == -1) 
		{
			dp[k + 1][j][1] = parenthesis_count(s, k + 1, j, 1);
		} 

		if (dp[i][k - 1][0] == -1) 
		{
			dp[i][k - 1][0] = parenthesis_count(s, i, k - 1, 0);
		}

		if (dp[k + 1][j][0] == -1) 
		{
			dp[k + 1][j][0] = parenthesis_count(s, k + 1, j, 0);
		}

		if (s[k] == '&')
		{
			if (isTrue == 1)
				ans += dp[i][k-1][1] * dp[k+1][j][1];
			else
				ans += dp[i][k-1][0] * dp[k+1][j][0] + dp[i][k-1][1] * dp[k+1][j][0]
					+ dp[i][k-1][0] * dp[k+1][j][1];
		}
		else if (s[k] == '|')
		{
			if (isTrue == 1)
				ans += dp[i][k-1][1] * dp[k+1][j][1] + dp[i][k-1][1] * dp[k+1][j][0]
					+ dp[i][k-1][0] * dp[k+1][j][1];
			else
				ans = ans + dp[i][k-1][0] * dp[k+1][j][0];
		}
		else if (s[k] == '^')
		{
			if (isTrue == 1)
				ans = ans + dp[i][k-1][0] * dp[k+1][j][1] + dp[i][k-1][1] * dp[k+1][j][0];
			else
				ans = ans + dp[i][k-1][1] * dp[k+1][j][1] + dp[i][k-1][0] * dp[k+1][j][0];
		}
		dp[i][j][isTrue] = ans;
	}
	return ans;
}

// Driver Code
int main()
{
	string symbols;
	string operators;
    cin>>symbols;
    cin>>operators;
	string s;
	int j = 0;

	for (int i = 0; i < symbols.length(); i++) 
	{
		s.push_back(symbols[i]);
		if (j < operators.length())
			s.push_back(operators[j++]);
	}
	
	// We obtain the string T|T&F^T
	int n = s.length();
	
	// There are 4 ways
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
	// (T|((T&F)^T))
	memset(dp, -1, sizeof(dp));
	cout << parenthesis_count(s, 0, n - 1, 1);
	return 0;
}
