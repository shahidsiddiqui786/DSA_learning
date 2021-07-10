// That is a bitwise shift right operator (>>) and it shifts the number the designated amount of bits to the right. The solution is using bit manipulation to store the cell value, i, and j all in one integer. Each coordinate takes 6 bits of data so to access the cell value, for example, we can shift the value of next over by 12 bits, which drops both coordinates off the integer and just leaves the cell value.

// The value of i is in the range [0,49], so it can be expressed in 6 bits (2^6 or [0,63]).
// The value of j is in the range [0,49], so it can be expressed in 6 bits (2^6 or [0,63]).
// The cell value is in the range [0,2499], so it can be expressed in 12 bits (2^12 or [0,4096]).
// All three values can be expressed in 24 bits total, which will fit into one 32-bit integer.

// next (in binary) =  0 0 0 0 0 0 0 0|0 0 0 0 0 0 0 0 0 0 1 1|0 0 0 0 0 1|0 0 0 0 0 1
//                                    |<--   cell value    -->|<--  i  -->|<--  j  -->

// translates to:

// cell value = 3
// i = 1
// j = 1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,cellvalue;
    // 0 < i , j < 50;
    cin>>i>>j;
    cellvalue = ((i << 6 -1) & (j << 6 -1)) ;
    cout<<cellvalue;
}

//so to work on this , it's not complete