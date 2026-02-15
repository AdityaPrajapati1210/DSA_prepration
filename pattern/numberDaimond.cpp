#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the number:";
    cin >> n;
    int count = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout << "  ";
        }
        for(int j=0;j<(i+1);j++){
            cout << count << " ";
            count--;
        }
        count++;
        for(int j=0;j<i;j++){
            count++;
            cout << count << " ";
        }
        cout << endl;
        count++;
    }
};
    
