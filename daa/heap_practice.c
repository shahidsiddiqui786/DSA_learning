#include <stdio.h>

/*
 just a practice ass for daa ------
 heapSort in c
 basically we make a max heap of given array
 so we use heapify function which basically checks every ele
 ,if it is greater than its parent, right from second element of array
 because first element has no parent.
 Now , come to heap Sort We just follow few steps:-
   1) We delete root ele of Max-heap(i.e, our largest element ) and
      and store the right most ele of heap(i.e, last element of arr)
      in the root position.
   2) And Now we are Left with n-1 element of array as a heap and one
      blank place(last place of array) in array, so we store a copy of
      our largest ele(what we have deleted in step one) there.
   3) And Finally we again Heapify our heap of n-1 Size,
      then we repeat 1, 2,3 until we are left with heap of 0 size.

   Time Complexity:- Best|| Average || worst :-- nlogn;
   space Complexity:- 1 
*/

void heapify(int heap[], int n) {
    int c,root,temp;
    for (int i = 1; i < n; i++)
    {
        c = i;
        // so here we are checking is current el is in right pos. accord to max heap
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c]) 
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
}

void heapSort(int heap[], int n) {
    int j,temp,root,c;
     for (j = n - 1; j >= 0; j--)
    {
        temp = heap[0];
        //swap max element with rightmost leaf element
        heap[0] = heap[j];    
        heap[j] = temp;
        heapify(heap,j);
    } 
}
 
int main()
{
    int heap[100], n, i, j, c, root, temp;
 
    printf("\n Enter no of elements :");
    scanf("%d", &n);
    printf("\n Enter the nos : ");
    for (i = 0; i < n; i++)
       scanf("%d", &heap[i]);

    heapify(heap,n);
 
    printf("Heap array : ");
    for (i = 0; i < n; i++)
        printf("%d\t ", heap[i]);
    
    heapSort(heap,n);
    
    printf("\n The sorted array is : ");
    for (i = 0; i < n; i++)
       printf("\t %d", heap[i]);
}