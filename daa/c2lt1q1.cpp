#include<bits/stdc++.h>
using namespace std;

vector<int> vt;
vector<pair<pair<char,char>, int> > re1;

int search(string s, char top){
    for(int i=0;i<s.length();i++){
        if(s[i] == top){
            return i;
        }
    }
    return -1;
}

int fval(char st,char tp){
    char l1,l2;
    for(int i=0;i<re1.size();i++){
        l1 = re1[i].first.first;
        l2 = re1[i].first.second;
        if((l1 == st && l2 == tp) || (l1 == tp && l2 == st)){
            return re1[i].second;
        }
    }
    return -1;
}

int calculate(string s, char top){
    int val, pos = search(s,top);
    int k = pos,tsum1 = 0,tsum2 = 0,sum1=0,sum2=0;
    char st,tp= s[k];
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
    while(k<(s.length())){
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

void permutate(string s, int i,int l,char top,int *minval, string *mins){
    if(i == l){
        //check value
       
       int cal = calculate(s,top);
       
       if(cal != INT_MAX && cal < (*minval)){
          *minval = cal;
          *mins = s;
       }
       return ;
    }
    // if we are in b/w the places permutate for every possible letter
    for(int j=i;j!=l;j++){
        swap(s[i],s[j]);
        permutate(s,i+1,l,top,minval,mins);
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
        for(int i=0;i<e;i++){
            cin>>ch2>>ch3>>val;
            re1.push_back({{ch2,ch3},val});
        }
        string mins;
        int minval = INT_MAX;
        permutate(str,0,str.length(),topper,&minval,&mins);
        if(minval == INT_MAX) {
            cout<<"NIL"<<'\n';
        }
        else{
            cout<<minval<<'\n';
            for(int i=0;i<mins.length();i++){
                cout<<mins[i]<<" ";
            }
            cout<<'\n';
        }
    }
}