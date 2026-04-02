#include<iostream>
#include<stack>
#include<string>
using namespace std;


void reverseStr(string &str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }


    for(int i=0;i<str.length();i++){
        str[i] = s.top();
        s.pop();
    }
}

int main(){
    string str = "abcdefg";
    reverseStr(str);
    cout<<str<<endl;
    
}