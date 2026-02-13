#include <iostream>
using namespace std;
int main(){
    int x;
    int count=0;
    int ans=0;
    int multiply=1;
    cout << "Enter any number to check armgtrong : ";
    cin >> x;
    int y = x;
    while(x>0){
        count++;
        x/=10;
    }
    x=y;
    while(x>0){
        int rem = x%10;
        int multiply=1;
        for(int i=0;i<count;i++){
            multiply *= rem;
        }
        ans+=multiply;
        x/=10;

    }
    if (y == ans){
        cout << "Number is armstrong";
    }else{
        cout << "Not a armstrong";
    }

}