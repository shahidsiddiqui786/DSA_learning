#include <stdio.h>

int H[50]; 
int size = -1; 


int parent(int i) { 
	return (i - 1) / 2; 
} 

int leftChild(int i) { 
	return ((2 * i) + 1); 
} 

int rightChild(int i) { 
	return ((2 * i) + 2); 
} 

void shiftUp(int i) { 
	while (i > 0 && H[parent(i)] > H[i]) { 
		int temp = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = temp;
		i = parent(i); 
	} 
} 

void shiftDown(int i) { 
	int minIndex = i; 
	int l = leftChild(i); 

	if (l <= size && H[l] < H[minIndex]) { 
		minIndex = l; 
	}  
	int r = rightChild(i); 

	if (r <= size && H[r] < H[minIndex]) { 
		minIndex = r; 
	} 

	if (i != minIndex) { 
		int temp = H[minIndex];
        H[minIndex] = H[i];
        H[i] = temp;
		shiftDown(minIndex); 
	} 
} 

void Enqueue(int p) { 
	size = size + 1; 
	H[size] = p; 
	shiftUp(size); 
} 

void Dequeue() { 
	int result = H[0]; 
	H[0] = H[size]; 
	size = size - 1; 
	shiftDown(0); 
	printf("%d ",result);
} 
 
void changePriority(int i, int p) { 
	int oldp = H[i]; 
	H[i] = p; 
	if (p < oldp) { 
		shiftUp(i); 
	} 
	else { 
		shiftDown(i); 
	} 
} 

void printQueue() {
    printf("our Queue:- \n");
    for(int i=0;i<=size;i++){
        printf("%d ",H[i]);
    }
}

int main() 
{ 
	printf("Process start\n");
    Enqueue(43);
    printQueue();
    Enqueue(67);
    printQueue();
    Enqueue(32);
    Enqueue(68);
    Enqueue(13);
    printQueue();
    Dequeue();
    Dequeue();
    Enqueue(55);
    Enqueue(98);
    printQueue();
    Dequeue();
    Dequeue();
    Dequeue();
    printQueue();
    Dequeue();
    Dequeue();
    printQueue();
	return 0; 
} 
