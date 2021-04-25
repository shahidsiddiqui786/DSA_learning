#include<stdio.h>



int main() {
    int p;
    int arro[1001];
    int arre[1000];
    scanf("%d",&p);
    if(p%2 == 0){
       int s =0;
       int t=2;
        while(t<p){
            arro[s] = t;
            t += 2;
            s++;
        }  
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    if(arro[i]+arro[j]+arro[k] == p){
                        printf("%d %d %d\n",arro[i], arro[j], arro[k]);
                    }
                }
            }
        }
    }
    else{
        int s = 0;
        int t=1;
        while(t<p){
            arre[s] = t;
            t += 2;
            s++;
        }
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    if(arre[i]+arre[j]+arre[k] == p){
                        printf("%d %d %d\n",arre[i], arre[j], arre[k]);
                    }
                }
            }
        }
    }
}