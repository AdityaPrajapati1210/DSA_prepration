#include<iostream>
using namespace std;

int main(){

    int m , n;
    cout << "Enter rows of the matrix : ";
    cin >> m;
    cout << "Enter cols of the matrix : ";
    cin >> n;
    int arr[m][n];

    int sr = 0,er = m-1;
    int sc = 0,ec = n-1;

    int count = 1;
    while(count <= m*n){

        for(int i = sc;i<=ec;i++){
            arr[sr][i] = count;
            count++;
        }
        sr++;
        for(int i=sr;i<=er;i++){
            arr[i][ec] = count;
            count++;
        }
        ec--;
        for(int i=ec;i>=sc;i--){
            arr[er][i] = count;
            count++;
        }
        er--;
        for(int i=er;i>=sr;i--){
            arr[i][sc]=count;
            count++;
        }
        sc++;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] <<" ";
            if(arr[i][j] <= 9) cout << " ";
        

        }
        cout <<endl;
    }


}