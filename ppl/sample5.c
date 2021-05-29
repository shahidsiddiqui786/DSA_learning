#include <stdio.h>
//sample program

int main()
{
    int r=4;
    switch(r){
        case 3:
        printf("a");
        break;
        case 6:
        printf("b");
        break; 
        case 12:
        printf("c");
        break;
        case 14:
        printf("d");
        break;
        default:
        printf("z");
    }
    return 0;
}