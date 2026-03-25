#include<iostream>
#include<string>
using namespace std;

void printSub(string s, string ans){
    if(s.length() == 0){
        cout << ans <<endl;
        return;
    }

    char ch  = s[0];
    
    printSub(s.substr(1 , s.length()-1), ans + ch);
    printSub(s.substr(1 , s.length()-1), ans);
}

int main(){
    string s = "abc";
    int n = s.length();

    string ans = "";
    int idx = 0;

    printSub(s, ans);
}