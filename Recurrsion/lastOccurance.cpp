#include<iostream>
#include<vector>
using namespace std;

int first(vector<int> &vec ,int n ,int target){
    if(n < 0) return 999;

    if(vec[n] == target) return n;

    return first(vec ,n-1,target);
};


int main(){
    vector<int>vec = {1,2,4,7,6,7,3,3,5};
    cout << first(vec , vec.size(),3);
}