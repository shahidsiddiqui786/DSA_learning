#include<stdio.h>
#include<limits.h>
#include<string.h>
int hash(int m, int d) {
    int index = m*100;
    index += d;
    return index;
}
int deHashD(int index) {
    return (index%100);
}
int deHashM(int index) {
    return (index/100);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        char rollNo2[n][20];
        char courseId2[n][20];
        int arr[1232];
        int dt[13][32];
        for(int i=0;i<1232;i++){
            arr[i] = -1;
        }
        for(int i=0;i<n;i++){
           int m , d, marks;
           scanf("%s%s%d%d%d",rollNo2[i],courseId2[i],&marks,&d,&m); 
           int index = hash(m,d);
           if(arr[index] == -1){
              arr[index]= marks;
              dt[m][d]=i;
           }
           else{
               if(arr[index] == marks){
                    int dat,mnth;
                    dat = deHashD(index);
                    mnth = deHashM(index);
                     
                    if(strcmp(rollNo2[i],rollNo2[dt[mnth][dat]])<0 ){
                        dt[m][d]=i;
                    }
                }    
                else if(arr[index] < marks){
                    arr[index]= marks;
                    dt[m][d]=i;
                }
                
           }
        }
        while(q--){
            int sd,sm,ed,em;
            scanf("%d %d %d %d",&sd,&sm,&ed,&em);
            int start,end;
            start = hash(sm,sd);
            end = hash(em,ed);
            int maxMarks = INT_MIN;
            int maxIndex;
            for(int i=start;i<=end;i++){
                if(arr[i] > maxMarks){
                    maxMarks = arr[i];
                    maxIndex = i;
                }
                else if(arr[i] == maxMarks && maxMarks != -1) {
                    int dat1,mnth1,dat2,mnth2;
                    dat1 = deHashD(i);
                    mnth1 = deHashM(i);
                    dat2 = deHashD(maxIndex);
                    mnth2 = deHashM(maxIndex);
                    int prio=0;
                   
                    if(strcmp(rollNo2[dt[mnth1][dat1]], rollNo2[dt[mnth2][dat2]])<0){
                         maxMarks = arr[i];
                         maxIndex = i;
                    }
                }
                
            }
            if(maxMarks == -1){
               printf("NIL\n");
            }
            else{
                int dat, mnth;
                dat = deHashD(maxIndex);
                mnth = deHashM(maxIndex);
                printf("%s %s %d %d %d\n",rollNo2[dt[mnth][dat]],courseId2[dt[mnth][dat]],arr[maxIndex],dat,mnth);
            }
        }
    }
}