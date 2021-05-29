
// problem : https://www.codechef.com/COOK39/problems/PPXOR

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll SumXorSum(int arr[],int n)
{
    ll sum=0;
    for(int i=0;i<30;++i)
    {
        
        int ct=0;
        bool odd=false;
        
        for(int j=0;j<n;++j)
        {
            if(arr[j]&(1<<i))
            odd=(!odd);
            if(odd)
            ct++;
        }
        
        for(int j=0;j<n;++j)
        {
            sum+=((1<<i)*ct);
            if(arr[j]&(1<<i))
            ct=n-j-ct;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    cout<<SumXorSum(arr,n);
}