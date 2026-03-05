#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>vec = {        //in 2D vector number of cols are same or diff but in 2D array only same no. of cols exixts. 
        {1,2,3},
        {4,5},
        {6}
    };
    for(int i = 0 ;i<vec.size();i++){
        for(int j=0;j < vec[i].size();j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }


}