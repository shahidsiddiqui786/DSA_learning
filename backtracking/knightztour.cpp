//Given a N*N board with the Knight placed on the first block of an empty board. 
//Moving according to the rules of chess knight must visit each square exactly once.
//Print the order of each the cell in which they are visited.

#include <bits/stdc++.h>
using namespace std;

#define N 8


int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}



bool knightour(int x, int y, int movei, int sol[N][N],int xMove[N], int yMove[N])
{
	int k, next_x, next_y;
    //base  case
	if (movei == N * N){
         for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++)
                cout << " "<< sol[x][y] << " ";
            cout << endl;
        }
        cout<<'\n';
         return true;
    }

	
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (knightour(next_x, next_y, movei + 1, sol,xMove, yMove))
				return true;
	
			sol[next_x][next_y] = -1;
		}
	}
	return false;
}


int main()
{
	int sol[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            sol[i][j] = -1;
        }
    }
    
    // valid moves for knights //ya manually u need to think and write all 8 possible moves.
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
     
    // let placed knight at 0,0.  P.S: it's given
	sol[0][0] = 0;
	
    bool moves = knightour(0,0,1,sol,xMove,yMove);
	return 0;
}
