#include <stdio.h>
#include <string.h>
#include <math.h>

struct Student {
    char rollno[12];
    int aff;
};

void swap(struct Student *x, struct Student *y) 
{ 
    struct Student temp = *x; 
    *x = *y; 
    *y = temp; 
}

int parent(int i) { 
	return (i - 1) / 2; 
} 
int leftChild(int i) { 
	return ((2 * i) + 1); 
} 
int rightChild(int i) { 
	return ((2 * i) + 2); 
}

void shiftUp(struct Student st[],int i) { 
	while (i > 0 && st[parent(i)].aff <= st[i].aff) { 
        if(st[parent(i)].aff < st[i].aff ){
              swap(&st[parent(i)],&st[i]);
        }
		else if(st[parent(i)].aff == st[i].aff && strcmp(st[i].rollno, st[parent(i)].rollno) < 0){
			  swap(&st[parent(i)],&st[i]);
		}
		i = parent(i); 
	} 
}

void shiftDown(struct Student st[],int i,int size) { 
	int maxIndex = i; 
	int l = leftChild(i); 

	if (l <= size && (st[l].aff > st[maxIndex].aff || (st[l].aff == st[maxIndex].aff && strcmp(st[l].rollno,st[maxIndex].rollno) < 0))) { 
        maxIndex = l; 
	}  
	int r = rightChild(i); 

	if (r <= size && (st[r].aff > st[maxIndex].aff || (st[r].aff == st[maxIndex].aff && strcmp(st[r].rollno,st[maxIndex].rollno) < 0))) { 
		maxIndex = r; 
	} 

	if (i != maxIndex) { 
        swap(&st[maxIndex],&st[i]);
        shiftDown(st,maxIndex,size);
	} 
}

int ExtractMax(struct Student st[],int size) {  
	st[0].aff = st[size].aff;
    strcpy(st[0].rollno,st[size].rollno);
	size = size - 1; 
	shiftDown(st,0,size);
	return size; 
}

void insert(struct Student st[], int i) {  
    scanf("%s%d",st[i].rollno,&st[i].aff);
	shiftUp(st,i);
}

void changeElementToHalf(struct Student st[],int size) { 
	int num1 = floor((double)st[0].aff/2.0);
	st[0].aff = num1;
	shiftDown(st,0,size);
}

int main() 
{   
	int t;
    scanf("%d",&t);
    while(t--) {
		int n;
        int size1 = -1;
        int size2 = -1;
        scanf("%d",&n);
		struct Student st1[n];
	    struct Student st2[n];
		for(int i=0;i<n;i++){
		    size1++;
			insert(st1,size1);
		}
		for(int i=0;i<n;i++){
		    size2++;
			insert(st2,size2);
		}
		while(size1>=0 || size2 >=0){
            int sum = (st1[0].aff) + (st2[0].aff);
             if(sum%2 == 0){
                printf("%s %s\n",st1[0].rollno,st2[0].rollno);
               size1 = ExtractMax(st1,size1);
               size2 = ExtractMax(st2,size2); 
             }
             else{
                changeElementToHalf(st1,size1);
				changeElementToHalf(st2,size2);
             }
		}
	}

} 
