// Problem: Given a string s of length n, consisting only of lowercase English letters, find the number of different substrings in this string.

// To solve this problem, we iterate over all substring lengths l=1…n. For every substring length l we construct an array of hashes of all substrings of length l multiplied by the same power of p.
// The number of different elements in the array is equal to the number of distinct substrings of length l in the string. This number is added to the final answer.

// For convenience, we will use h[i] as the hash of the prefix with i characters, and define h[0]=0.

#include<bits/stdc++.h>
using namespace std;

int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

int main() {

    string s;
    cin>>s;
    int ct = count_unique_substrings(s);
    cout<<ct;

}