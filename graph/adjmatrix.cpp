#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    char v[n];
    char tp;
    int arr[n][n] = {0};
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        for(int j=0;j<l;j++){
            cin>>tp;
            int temp;
            for(int k =0;k<n;k++){
                if(v[k] == tp){
                    temp = k;
                    break;
                }
            }
            arr[i][temp] = 1;
        }
    }

    //print
    for (int i=0;i<n;i++) 
    { 
        cout << "\n Adjacency list of vertex "
             << v[i] << "\n head "; 
        for (int k=0;k<n;k++){
            if(arr[i][k] == 1){
                cout<<v[k]<<" ";
            }
        }  
    } 
}