#include<iostream>
using namespace std;


int paring(int n){
    if(n == 1 || n==2) return n;

    int ans1 = paring(n-1);  //single

    int ans2 = (n-1)*paring(n-2);  //pair

    return ans1 + ans2;
}

int main(){
    cout << paring(3) <<endl;
}