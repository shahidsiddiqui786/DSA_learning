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
#define pii <pair<pair<int,int>,int> 
#define ff first
#define ss second
#define vi vector<int>
#define vip vector<pair<int,int>>
#define sip set<pair<int,int>>
#define si set<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test ll t,no=1; cin>>t; while(t--){ solve(); no++;};
//__________________________________________________________//
 

struct event {
    string event_name;
    int date;
    int month;
    string cat;
    int level;
};

bool comp(event a,event b){
    return (a.month <= b.month) && (a.date < b.date) ;
}

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


void solve(){
    
    vector<event> v;
    int n,a,b,c;
    string eve,cat;

    cin>>n;
    loop(i,0,n){
        cin>>eve>>a>>b>>cat>>c;
        event xyz = {eve,a,b,cat,c};
        v.push_back(xyz);
    }

    sort(v.begin(),v.end(),comp);

    // loop(i,0,n){
    //     cout<<v[i].date<<" "<<v[i].month<<'\n';
    // }
    
    unordered_map<int,vector<int>> umap;
    set<int> saricat;
    loop(i,0,n){
        int val = compute_hash(v[i].cat);
        umap[val].push_back(v[i].level);
        saricat.insert(val);
    }

    set<int>::iterator it;
    int totalans = 0;
    for(it = saricat.begin();it!=saricat.end();++it){
        int lis[n];
        cout<<*it<<" ";
        lis[0] = 1;  
    

        loop(i,1,n)
        {
            lis[i] = 1;
            loop(j,0,i) 
                if ( (umap[*it][i] > umap[*it][j]) && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }
    
        int ans = *max_element(lis, lis+n);
        totalans += ans;
    }
    cout<<totalans<<'\n';
}

int main(){
    fastio
    test
    return 0;
}

