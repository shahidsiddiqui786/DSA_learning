#include<iostream>
using namespace std;

int main() {
    int* x = new int;
    int* y = new int;
    int* z = new int;
    *x = 3;
    *y = 8;
    *z = 13;
    cout<<(*x+*y+*z);
    delete x;
    delete y;
    delete z;
    return 0;
}