#include<iostream>
#include<string>
using namespace std;

void printSub(string s, string ans[], int n, int i, int &idx){
    if(i == n){
        return;
    }

    string temp = "";
    for(int k = i; k < n; k++){
        temp += s[k];
        ans[idx++] = temp;   // store substring
    }

    printSub(s, ans, n, i+1, idx);
}

int main(){
    string s = "abc";
    int n = s.length();

    string ans[100];
    int idx = 0;

    printSub(s, ans, n, 0, idx);

    // print all substrings
    for(int i = 0; i < idx; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}