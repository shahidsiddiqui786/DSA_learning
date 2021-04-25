// Problem: Given a list of n strings si, each no longer than m characters, find all the duplicate strings and divide them into groups.

// From the obvious algorithm involving sorting the strings, we would get a time complexity of O(nmlogn) where the sorting requires O(nlogn) comparisons and each comparison take O(m) time. However, by using hashes, we reduce the comparison time to O(1), giving us an algorithm that runs in O(nm+nlogn) time.

// We calculate the hash for each string, sort the hashes together with the indices, and then group the indices by identical hashes.

#include<bits/stdc++.h>
using namespace std;

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


vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

int main() {

    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int> > vec;
    vec = group_identical_strings(v);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<v[vec[i][j]]<<" ";
        }
        cout<<'\n';
    }

}