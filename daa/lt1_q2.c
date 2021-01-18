#include<stdio.h>
#include<limits.h>

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        char rollNo[n][15];
        char courseId[n][15];
        int arr[n][3];

        int maxMarksInDay[13][32];
        int maxMarksInReverseDay[13][32];
        for(int i=0;i<13;i++){
            for(int j=0;j<32;j++){
                maxMarksInDay[i][j]=-1;
                maxMarksInReverseDay[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            scanf("%s%s%d%d%d",rollNo[i],courseId[i],&arr[i][0],&arr[i][1],&arr[i][2]);
            
            if(maxMarksInDay[arr[i][2]][arr[i][1]] != -1){
               if(arr[maxMarksInDay[arr[i][2]][arr[i][1]]][0]<arr[i][0]) {
                    maxMarksInDay[arr[i][2]][arr[i][1]] = i;
                    maxMarksInReverseDay[arr[i][2]][arr[i][1]] = i;
                   
               }
            }
            else{
                maxMarksInDay[arr[i][2]][arr[i][1]] = i;
                maxMarksInReverseDay[arr[i][2]][arr[i][1]] = i;
                
            }
        }
        for(int i=1;i<13;i++){
            for(int j=1;j<32;j++){
                if(j!=1){
                    if(maxMarksInDay[i][j-1]!=-1){
                        if(maxMarksInDay[i][j] == -1 ||(maxMarksInDay[i][j] != -1 && arr[maxMarksInDay[i][j]][0]<arr[maxMarksInDay[i][j-1]][0])){
                            maxMarksInDay[i][j] = maxMarksInDay[i][j-1];
                        }
                    }
                }
            }
            for(int j=31;j>0;j--){
                if(j!=31){
                    if(maxMarksInReverseDay[i][j+1]!=-1){
                        if(maxMarksInReverseDay[i][j]==-1 ||(maxMarksInReverseDay[i][j]!=-1 && arr[maxMarksInReverseDay[i][j]][0]<arr[maxMarksInReverseDay[i][j+1]][0])){
                            maxMarksInReverseDay[i][j] = maxMarksInReverseDay[i][j+1];
                        }
                    }
                }
            }
        }
        while(q--){
            int sd,sm,ed,em;
            scanf("%d%d%d%d",&sd,&sm,&ed,&em);
            int maxMarks = INT_MIN;
            int maxMarksBoy;

            if(sm == em){
                if(maxMarksInDay[sm][sd] != maxMarksInDay[sm][ed] || maxMarksInReverseDay[sm][sd] != maxMarksInReverseDay[sm][ed]){
                    int k = ed;
                    while(k>sd) {
                        if(maxMarksInDay[sm][k]>maxMarksInDay[sm][k-1]){
                            maxMarksBoy = maxMarksInDay[sm][k];
                            printf("%d\n",maxMarksBoy);
                            break;
                        }
                        maxMarksBoy = -1;
                        k--;
                    }
                    int j=sd;
                    if(maxMarksBoy == -1){
                      while(j<ed){
                          if(maxMarksInReverseDay[sm][j]>maxMarksInReverseDay[sm][j+1]){
                              maxMarksBoy = maxMarksInReverseDay[sm][j];
                              printf("%d\n",maxMarksBoy);
                              break;
                          }
                          j++;
                      }
                    }
                }
                else{
                    int val1 = maxMarksInDay[sm][sd];
                    int date1 = arr[val1][1];
                    int val2 = maxMarksInReverseDay[sm][sd];
                    int date2 = arr[val2][1];
                    if(date1>=sd && date1<=ed){
                        maxMarksBoy = val1;
                    }
                    else if(date2>=sd && date2<=ed){
                        maxMarksBoy = val2;
                    }
                    else{
                        maxMarksBoy = -1;
                    }
                }
            }
            else{
                if((maxMarksInDay[sm][sd]!=-1) && (arr[maxMarksInReverseDay[sm][sd]][0] > maxMarks)){
                maxMarks = arr[maxMarksInReverseDay[sm][sd]][0];
                maxMarksBoy = maxMarksInReverseDay[sm][sd];
                }
                if((maxMarksInDay[em][ed]!=-1) && (arr[maxMarksInDay[em][ed]][0] > maxMarks)) {
                    maxMarks = arr[maxMarksInDay[em][ed]][0];
                    maxMarksBoy = maxMarksInDay[em][ed];
                }
                for(int i=sm+1;i<em;i++){
                    if((maxMarksInDay[i][31]!=-1) && (arr[maxMarksInDay[i][31]][0] > maxMarks)) {
                    maxMarks = arr[maxMarksInDay[i][31]][0];
                    maxMarksBoy = maxMarksInDay[i][31];
                    }
                }
            }
            if(maxMarksBoy == -1){
                printf("NIL\n");
            }
            else{
                printf("%s %s %d %d %d\n",rollNo[maxMarksBoy],courseId[maxMarksBoy],arr[maxMarksBoy][0],arr[maxMarksBoy][1],arr[maxMarksBoy][2]);
            }
        }
    }
}

