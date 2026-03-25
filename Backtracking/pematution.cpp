#include<iostream>
#include<string>
using namespace std;

void permatution(string s , string ans){
    int n = s.length();
    if(n == 0){
        cout << ans <<endl;
        return;
    }

    for(int i=0;i<n;i++){
        char ch = s[i];
        string newstr = s.substr(0 , i) + s.substr(i+1 , n-i-1);
        permatution(newstr , ans+ch);
    }

}

int main(){
    string s = "abcd";
    int n = s.length();
    string ans;

    permatution(s,ans);

}