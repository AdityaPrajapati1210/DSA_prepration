#include<iostream>
#include<string>
#include<stack>
using namespace std;

string decode(string s){
    stack<string>str;
    stack<int>number;
    int num = 0;
    string curr = "";
    int n = s.length();
    for(char ch : s){
        if(isdigit(ch)){
            num = num*10 + (ch - '0');
        }else if(ch == '['){
            number.push(num);
            str.push(curr);
            num = 0;
            curr = "";
        }else if(ch == ']'){
            int repeat = number.top();
            number.pop();
            string prev = str.top();
            str.pop();
            string temp = "";
            for(int i=0;i<repeat;i++){
                temp += curr;
            }
            curr = prev + temp;
        }else{
            curr += ch;
        }
    }
    return curr;
}


int main(){
    string str = "3[a]3[ab]";
    string decoded = decode(str);
    cout << decoded<<endl;

}