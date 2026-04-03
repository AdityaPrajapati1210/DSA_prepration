#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool check(string str){
    stack<char> st;
    
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        
        // Opening brackets
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            // If stack empty → invalid
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            // Matching condition
            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[')){
                return false;
            }
        }
    }
    
    // If stack empty → valid
    return st.empty();
}

int main(){
    string s = "({}){}[]";

    if(check(s)){
        cout <<"Valid"<<endl;
    }else{
        cout <<"Invalid"<<endl;
    }
}