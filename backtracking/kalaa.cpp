#include<bits/stdc++.h>
using namespace std;

vector<int> vt;

int search(string s, char top){
    for(int i=0;i<s.length();i++){
        if(s[i] == top){
            return i;
        }
    }
    return -1;
}

int calculate(string s, char top, map<string, int> umap){
    int pos = search(s,top);
    int k = pos,sum1=0,sum2=0;
    while(k>0){
         string str1 = s.substr(k-1,2);
         
         if(umap[str1]){
              sum1 += umap[str1];
         }
         else{
             return INT_MAX;
         }
         k--;
    }
    k = pos;
    while(k<(s.length()-1)){
         string str1 = s.substr(k,2);
         cout<<umap[str1]<<" ";
         if(umap[str1]){
              sum2 += umap[str1];
         }
         else{
             return INT_MAX;
         }
        k++;
    }
    return (sum1+sum2);
}

void permutate(string s, int i,int l,char top,const map<string, int> &umap){
    if(i == l){
        //check value
       
       int cal = calculate(s,top,umap);
       
       if(cal != INT_MAX){
           vt.push_back(cal);
       }
       return ;
    }
    // if we are in b/w the places permutate for every possible letter
    for(int j=i;j!=l;j++){
        swap(s[i],s[j]);
        permutate(s,i+1,l,top,umap);
        swap(s[i],s[j]);
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        vt.clear();
        int n;
        cin>>n;
        char topper,ch1,ch2,ch3;
        cin>>topper;
        string str,str1,str2;
        for(int i=0;i<(n-1);i++){
            cin>>ch1;
            str += ch1;
        }
        str += topper;
        int e,val;
        cin>>e;
        map<string, int> umap;
        for(int i=0;i<e;i++){
            cin>>ch2>>ch3>>val;
            str1 += ch2;
            str1 += ch3;
            str2 += ch3;
            str2 += ch3;
            umap[str1] = val;
            umap[str2] = val;
            
        }
        
        permutate(str,0,str.length(),topper,umap);
        if(vt.size() == 0) {
            cout<<"NIL"<<'\n';
        }
        else{
            sort(vt.begin(),vt.end());
            cout<<vt[0]<<'\n';
        }
    }
}