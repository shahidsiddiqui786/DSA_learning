#include<stdio.h>
#include<string.h>


// int hash(char n[]){
//     int mod = 1000007;
//     int sum = 0;
//     for(int i=0;n[i];i++){
//        sum += n[i]*i;
//        sum = sum%mod;
//     }
//     return sum%mod;
// }

int main() {
  
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char username[n][20];
        char fname[n][20];
        char lname[n][20];
        char city[n][20];
        int phone[n];

        for(int i=0;i<n;i++){
            char fc[20];
            scanf("%s",fc);
            int size = -1;
            if(strcmp(fc,"add") == 0){
                size++;
                scanf("%s",username[size]);
                scanf("%s",fname[size]);
                scanf("%s",lname[size]);
                scanf("%s",city[size]);
                scanf("%d",&phone[size]);
                printf("added\n");
            }
            else if(strcmp(fc,"search_username") == 0){
                char su[20];
                scanf("%s",su);
                 int flg = 0;
                for(int j= 0;j<=size;j++){
                    if(strcmp(username[j],su) == 0){
                        printf("%s %s %s %s %d\n",username[j],fname[j],lname[j],city[j],phone[j]);
                        flg = 1;
                        break;
                    }
                }
                if(!flg){
                    printf("NIL\n");
                } 
            }
            else if(strcmp(fc,"search_phone") == 0){
                int sp;
                scanf("%d",&sp);
                 int flg = 0;
                for(int j= 0;j<=size;j++){
                    if(phone[j] == sp){
                        printf("%s %s %s %s %d\n",username[j],fname[j],lname[j],city[j],phone[j]);
                        flg = 1;
                        break;
                    }
                }
                if(!flg){
                    printf("NIL\n");
                }
            }
            else if(strcmp(fc,"modify_username") == 0){
                char su[20];
                scanf("%s",su);
                 int flg = 0;
                for(int j= 0;j<=size;j++){
                    if(strcmp(username[j],su) == 0){
                        scanf("%s",username[size]);
                        scanf("%s",fname[j]);
                        scanf("%s",lname[j]);
                        scanf("%s",city[j]);
                        scanf("%d",&phone[j]);
                        printf("modified\n");
                        flg = 1;
                        break;
                    }
                }
                if(!flg){
                    printf("NIL\n");
                } 
            }
            else if(strcmp(fc,"modify_phone") == 0){
                  int sp;
                scanf("%d",&sp);
                 int flg = 0;
                for(int j= 0;j<=size;j++){
                    if(phone[j] == sp){
                        scanf("%s",username[size]);
                        scanf("%s",fname[j]);
                        scanf("%s",lname[j]);
                        scanf("%s",city[j]);
                        scanf("%d",&phone[j]);
                        printf("modified\n");
                        flg = 1;
                        break;
                    }
                }
                if(!flg){
                    printf("NIL\n");
                }
            }

        }
    }
}