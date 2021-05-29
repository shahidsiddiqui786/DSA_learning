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
 
void findNoOf1(int n){
    //TC no of bit 1 presnent in number
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    cout<<cnt<<'\n';
}

void findNoOf1II(int n){
    //TC log(n)
    int cnt  = 0;
    while(n!=0){
    if(n&1) cnt++;
    n = n>>1;
    }
    cout<<cnt<<'\n';
}

void solve(int caseno)
{
    int n;
    cin>>n;
    findNoOf1(n);
    findNoOf1II(n);
}

 int main() {
    fastio;
    solve(0);
    return 0;
}

