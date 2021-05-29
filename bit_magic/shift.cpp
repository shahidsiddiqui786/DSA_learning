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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test ll t,no=1; cin>>t; while(t--){ solve(no); no++;};
//__________________________________________________________//

void findIthBit(int n,int i) {
     n = n>>i;
     if(n&1) cout<<1<<'\n';
     else cout<<0<<'\n';
}

void findIthBitII(int n,int i) {
    if(n & (1<<i)) cout<<1<<'\n';
    else cout<<0<<'\n';
}

int setIthBitTo1(int n,int i) {
    return (n | (1<<i));
}

int setIthBitTo0(int n,int i) {
    return (n | (~(1<<i)));
}
 
void solve(int caseno)
{
   int n,i;
   cin>>n>>i;
   findIthBit(n,i-1);
   findIthBitII(n,i-1);
   cout<<setIthBitTo1(n,i-1)<<'\n';
   cout<<setIthBitTo0(n,i-1)<<'\n';
}

int main() {
    fastio;
    solve(0);
    return 0;
}



