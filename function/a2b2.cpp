#include<iostream>
using namespace std;

int  formnula( int a ,int b){
    return (a*a) + (b*b) + (2*a*b);
}
int main(){
   cout << formnula(4,5) << endl;
}