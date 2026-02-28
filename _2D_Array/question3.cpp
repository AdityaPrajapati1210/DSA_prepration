// Question3:Write a program to Find Transpose of a Matrix.What is Transpose?
// Transpose of a matrix is the process of swapping the rows to columns.
// For a 2x3 matrix,
// Matrix 
//           a11 a12 a13
//           a21 a22 a23 
// Transposed Matrix 
//          a11 a21 
//          a12 a22
//          a13 a23


#include<iostream>
using namespace std;

int main(){
    int m = 2, n = 3;
    int arr[m][n]={
        {4,7,8},
        {2,7,7}
    };
    int tran[n][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            tran[j][i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout << tran[i][j] << " ";
        }
        cout << endl;
    }


}