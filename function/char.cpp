#include<iostream>
using namespace std;

char  afterCh( char ch){
    if(ch == 'z') return 'a';
    return ch+1;
}
int main(){
   cout << afterCh('z') << endl;
}