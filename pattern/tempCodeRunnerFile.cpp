#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter a number :";
    cin >> n;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<i+1;j++){
            cout << "* ";
        }
        for(int j=0;j<(2*n-2*i-1);j++){
            cout << "  ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }