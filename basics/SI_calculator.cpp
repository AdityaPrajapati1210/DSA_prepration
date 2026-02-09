#include<iostream>
using namespace std;
int main(){
    float p;
    float r;
    float t;

    cout << "Enter Principal :";
    cin >> p;
    cout << "Enter rate :";
    cin >> r;
    cout << "Enter time :";
    cin >> t;

    cout << "Simple Intrest : "<<(p*r*t)/100<<endl;
}