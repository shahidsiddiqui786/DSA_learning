#include<stdio.h>
#include<stdbool.h>
#include<limits.h>



int main()
{
	int t, n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		char rollNo[n][11];
		int cordnt[n][2];
		bool isPrinted[n];
		for(int i=0;i<n;i++){
		   scanf("%s%d%d",rollNo[i],&cordnt[i][0],&cordnt[i][1]);
		   isPrinted[i] = false;
		}
        int pari = 0;
        for(int i=0;i<n;i++){
            int min = INT_MAX;
            int minDistBoy;
            for(int j=0;j<n;j++){
                int dist = ((cordnt[pari][0]-cordnt[j][0])*(cordnt[pari][0]-cordnt[j][0])+(cordnt[pari][1]-cordnt[j][1])*(cordnt[pari][1]-cordnt[j][1]));
                if(j!=pari && !isPrinted[j]){
                    if(min == dist){
                        int k=0;
                        for(;k<11;){
                            if(rollNo[minDistBoy][k]!=rollNo[j][k]){
                                break;
                            }
                            k++;
                        }
                        if(rollNo[minDistBoy][k]>rollNo[j][k]){
                             minDistBoy = j;
                        }
                    }
                    if(min>dist){
                        min = dist;
                        minDistBoy = j;
                    }
                }
            }
            printf("%s\n",rollNo[pari]);
            isPrinted[pari]=true;
            pari = minDistBoy;
        }
	}
}