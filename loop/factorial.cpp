#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter a number:";
    cin >> n;
    int ans=1;

    // find factorial
    for(int i=1;i<=n;i++){
        ans*=i;
    }

    cout << ans <<endl;
}