#include<iostream>
using namespace std;

int countSub(string s, int st, int end){

    // base case
    if(st == s.length())
        return 0;

    if(end == s.length())
        return countSub(s, st+1, st+1);

    int count = 0;

    string temp = s.substr(st, end-st+1);

    if(temp[0] == temp[temp.length()-1]){
        count = 1;
    }

    return count + countSub(s, st, end+1);
}

int main(){
    string s = "abcab";
    cout << countSub(s,0,0);
}