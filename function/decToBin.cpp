#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int ans = 0;
    int pow = 1;
    while(n > 0){
        int rem = n%2;
        ans += pow*rem;
        pow*=10;
        n/=2;
    }
    cout << ans << endl;
}