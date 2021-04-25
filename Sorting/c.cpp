// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

/*  
   // Quick Sort Implementation using Iteration
*/

#include <bits/stdc++.h>
using namespace std;

class Matrix {
   public:
      void setRow(int row) {
          row = row;
      }
      void setCol(int Col) {
          column = Col;
      }
      void setInput(int a[],int size, int rowno){
           for(int i=0;i<size;i++){
              this->arr[rowno][i] = a[i];
           }
      }
      void printResult() {
        //   for(int i=0;i<row;i++){
        //       for(int j=0;j<column;j++){
        //           cout<<this->arr[i][j]<<" ";
        //       }
        //       cout<<'\n';
        //   }
        cout<<row<<" "<<column;
      }
    //   bool isValidAddition(const Matrix& b) {
    //        if(this->row == b.row && this->column == b.column){
    //            return true;
    //        }
    //        return false;
    //   }
    //   bool isValidAddition(const Box& b) {
    //        if(row == b.row && column == b.column){
    //            return true;
    //        }
    //        return false;
    //   }
      
      
      Matrix operator+(const Matrix& b) {
         
            Matrix mat;
            for(int i = 0;i<row;i++){
                for(int j=0;j<column;j++){
                    mat.arr[i][j] = this->arr[i][j] + b.arr[i][j];
                }
            }
            return mat;
          
      }
      
      int row;
      int column;
      int arr[100][100];
};

int main()
{
    int n,m;
    cin>>n>>m;
    Matrix m1;
    Matrix m2;
    Matrix m3;

    m1.setRow(n);
    m1.setCol(m);

    m2.setRow(n);
    m2.setCol(m);

    int arr[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[j];
        }
        m1.setInput(arr,m,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[j];
        }
        m2.setInput(arr,m,i);
    }

    m3 = m1+m2;
    m1.printResult();

}


include<iostream>

 class matrix2;
 class matrix1
 
{
            int a[5][5];                       
            int m,n;
  public:
            void getmatrix1();
            void putmatrix1();
            friend void matrixsum(matrix1,matrix2);
};

void matrix1::getmatrix1()

{
 
            int i,j;\
            cout<<"MATRIX 1:\n";
            cout<<"Rows and Columns: ";
            cin>>m>>n;
            cout<<"Enter elements:\n"; 
            for(i=0;i<m;i++)
            for(j=0;j<n;j++) 
            cin>>a[i][j];
 
}
 
void matrix1::putmatrix1()
 
{
            int i,j; 
            cout<<"MATRIX 1:\n";
            for(i=0;i<m;i++)
            {
                        for(j=0;j<n;j++)
                                    cout<<a[i][j]<<" ";
                        cout<<endl;
            }
}

class matrix2 
{
            int b[5][5];
            int m,n;
public:
            void getmatrix2();
            void putmatrix2();
            friend void matrixsum(matrix1,matrix2);
};
 
void matrix2::getmatrix2() 
{
            int i,j;
            cout<<"MATRIX 2:\n";
            cout<<"Rows and Colums: ";
            cin>>m>>n;
            cout<<"Enter elements:\n";
            for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                        cin>>b[i][j];
}

void matrix2::putmatrix2() 
{
            int i,j;
            cout<<"MATRIX 2:\n";
            for(i=0;i<m;i++)
            {
                        for(j=0;j<n;j++)
                                    cout<<b[i][j]<<" ";
                        cout<<endl;
            }
}

void matrixsum(matrix1 g,matrix2 h) 
{

            int i,j; 
            if(g.m==h.m && g.n==h.n)
            {
                         cout<<"SUM OF MATRICES:\n"; 
                           for(i=0;i<g.m;i++)
                        {

                                    for(j=0;j<g.n;j++) 
                                                cout<<g.a[i][j]+h.b[i][j]<<" ";
                                    cout<<endl; 
                        }
            }
            else
                        cout<<"Dimensions are not same...Addition not possible";
}

int main()
{
            matrix1 m1;
            matrix2 m2;
            m1.getmatrix1();                    
            m2.getmatrix2();
            m1.putmatrix1();                    
            m2.putmatrix2();
            matrixsum(m1,m2);
}
