#include<iostream>
using namespace std;

int tiling(int n){
    // base condition
    if(n ==0 || n ==1) return 1;

    int ans = tiling(n-1) + tiling(n-2);
    return ans;
}

int main(){
    cout << tiling(3) <<endl;
}


