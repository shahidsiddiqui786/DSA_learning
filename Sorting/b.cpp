// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

/*  
   // Quick Sort Implementation using Iteration
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition(int arr[], int low, int high) {
    
    int pivotElement = arr[low];
    int i = high+1;

    for(int j=high;j>=low+1;j--){
        if(arr[j]>pivotElement) {
            i--;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i-1],&arr[low]);
    return (i-1);
}

void QuickSortWithIteration(int arr[], int low, int high) {
    
     int stack[high-low+1];
     int top = -1;

     stack[++top] = low;
     stack[++top] = high;

     while(top >= 0){

        high = stack[top--];
        low = stack[top--];

        int pivotElementPosition = partition(arr,low,high);

        if(pivotElementPosition-1 > low){
            stack[++top] = low;
            stack[++top] = pivotElementPosition-1;
        }
        if(pivotElementPosition+1 < high){
            stack[++top] = pivotElementPosition + 1;
            stack[++top] = high;
        }
     }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    QuickSortWithIteration(arr,0,n-1);
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
}
