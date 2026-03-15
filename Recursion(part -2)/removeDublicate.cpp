#include<iostream>
using namespace std;

bool present(string ans, char ch){
    for(char c : ans){
        if(c == ch) return true;
    }
    return false;
}

string remove(string s ,string ans,int i){
    if(i >= s.length()) return ans;
    
    if(!present(ans,s[i])){
        ans+=s[i];
    }
    return remove(s ,ans ,i+1);
}


int main(){
    string s = "appnnacollege";
    string t ="";
    cout << remove(s , t,0);
}