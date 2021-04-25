// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

/*  
   // Quick Sort Implementation using Recursion
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

void QuickSort(int arr[], int low, int high) {
    
     if( low > high) {
         return;
     }

     int pivotElementPosition = partition(arr,low,high);

     QuickSort(arr,low,pivotElementPosition-1);
     QuickSort(arr,pivotElementPosition+1, high);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
}
