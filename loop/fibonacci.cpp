#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"Enter the number :";
    cin >> n;

    int count = 2;
    int f =0,s=1;
    cout << f <<" " << s <<" ";
    while(count <= n){
        cout << f+s << " ";
        int temp = s;
        s = f+s;
        f = temp;
        count++;
    }
}