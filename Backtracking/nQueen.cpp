#include<iostream>
#include<vector>
using namespace std;


void printboard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0;i < n;i++){
        for(int j =0 ;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}


bool isSafe(vector<vector<char>> board, int row , int col){
    // horiZontal
    for(int i=0;i<board.size();i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // vertical
    for(int i=0;i<row;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // daigonal
    for(int i=row,j = col;(i>=0)&&(j>=0) ;i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // daigonal
    for(int i=row,j = col;(i>=0)&&(j<board.size()) ;i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }



    return  true;
}


// int Nqueen(vector<vector<char>> board , int row){
//     int  n = board.size();
//     if( row == n){
//         printboard(board);
//         cout<<"_______________________"<<endl;
//         return 1;
//     }
//     int count = 0;
//     for(int i=0;i<n;i++){
//         if(isSafe(board,row,i)){
//             board[row][i] = 'Q';
//             count += Nqueen(board,row+1);
//             board[row][i] = '_';
//         }
//     }
//     return count;

// }


bool Nqueen(vector<vector<char>> &board , int row){
    int n = board.size();

    if(row == n){
        printboard(board);
        return true;   // stop after first solution
    }

    for(int i = 0; i < n; i++){
        if(isSafe(board, row, i)){
            board[row][i] = 'Q';

            if(Nqueen(board, row + 1))  // if solution found
                return true;

            board[row][i] = '_'; // backtrack
        }
    }

    return false;
}

int main(){
    vector<vector<char>> board;
    int n = 4;

    for(int i=0;i < n;i++){
        vector<char>row = {};
        for(int j =0 ;j<n;j++){
            row.push_back('_');
        }
        board.push_back(row);
    }
    Nqueen(board , 0);

    // printboard(board);
}