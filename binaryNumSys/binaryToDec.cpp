#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int ans = 0;
    int pow = 1;
    while(n > 0){
        int rem = n%10;
        if(rem == 0  || rem == 1){
            ans += rem*pow;
            pow*=2;
            n/=10;
        }else{
            cout << "It is not a binary number.";
            return 0;
        }
    }
    cout << ans << endl;
}