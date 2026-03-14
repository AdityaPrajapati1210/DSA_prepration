#include<iostream>
#include<vector>
using namespace std;

int first(vector<int> &vec , int i,int target){
    if(i >= vec.size()) return 999;

    if(vec[i] == target) return i;

    return first(vec , i+1,target);
};


int main(){
    vector<int>vec = {1,2,4,5,6,7,3,3,3};
    cout << first(vec , 0,3);
}