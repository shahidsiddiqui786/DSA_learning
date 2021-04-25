#include<bits/stdc++.h>
using namespace std;

vector<int> vt;
vector<pair<pair<string,string>, int> > re1;
string mins[16];

int search(string s[], string top, int n){
    for(int i=0;i<n;i++){
        if(s[i] == top){
            return i;
        }
    }
    return -1;
}

int fval(string st,string tp){
    string l1,l2;
    for(int i=0;i<re1.size();i++){
        l1 = re1[i].first.first;
        l2 = re1[i].first.second;
        if((l1 == st && l2 == tp) || (l1 == tp && l2 == st)){
            return re1[i].second;
        }
    }
    return -1;
}

int calculate(string s[], string top, int n){
    int val, pos = search(s,top,n);
    int k = pos,tsum1 = 0,tsum2 = 0,sum1=0,sum2=0;
    string st,tp= s[k];
    k--;
    while(k>=0){
         st = s[k];
         val = fval(st,tp);
         if(val == -1) return INT_MAX;
         sum1 += val;
         tsum1 += sum1;
         tp = st;
         k--;
    }
    k = pos;
    tp = s[k];
    k++;
    while(k<(n)){
        st = s[k];
         val = fval(st,tp);
         
         if(val == -1) return INT_MAX;
        sum2 += val;
        tsum2 += sum2;
        tp = st;
        k++;
    }
    // cout<<tsum1<<" "<<tsum2<<'\n';
    return (tsum1+tsum2);
}

int alphabet(string a[], string b[],int l){
      int k=0;
        for(;k<l;){
            if(a[k]!=b[k]){
                break;
            }
            k++;
        }
        if((a[k] < b[k])){
            return -1;
        }
        return 1;
}

void permutate(string s[], int i,int l,string top,int *minval){
    if(i == l){
        //check value
       
       int cal = calculate(s,top,l);
       
       if(cal != INT_MAX && cal < (*minval)){
          *minval = cal;
           for(int i=0;i<l;i++){
               mins[i] = s[i];
           }
       }
       else if(cal == (*minval)){
           
           if(alphabet(s, (mins), l) < 0){
                for(int i=0;i<l;i++){
                    mins[i] = s[i];
                }
           } 
       }
       return ;
    }

    // if we are in b/w the places permutate for every possible letter
    for(int j=i;j!=l;j++){
        swap(s[i],s[j]);
        if(i > 0 && fval(s[i],s[i-1]) != -1){
            // cout<<<<" ";
            permutate(s,i+1,l,top,minval);
        }
        else if(i == 0){
            permutate(s,i+1,l,top,minval);
        }
        swap(s[i],s[j]);
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        vt.clear();
        re1.clear();
        int n;
        cin>>n;
        string topper,ch2,ch3;
        string str[n];
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        topper = str[0];
        int e,val;
        cin>>e;
        for(int i=0;i<e;i++){
            cin>>ch2>>ch3>>val;
            re1.push_back({{ch2,ch3},val});
        }
        
        int minval = INT_MAX;
        permutate(str,0,n,topper,&minval);
        if(minval == INT_MAX) {
            cout<<"NIL"<<'\n';
        }
        else{
            cout<<minval<<'\n';
            for(int i=0;i<n;i++){
                cout<<mins[i]<<" ";
            }
            cout<<'\n';
        }
    }
}