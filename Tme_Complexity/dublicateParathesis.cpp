#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool findDub(string str){
    int n = str.length();
    stack<int>st;
    for(int i=0;i<n;i++){
        char ch = str[i];
        if(ch != ')'){
            st.push(ch);
        }else{
            if(st.top() == '('){
                return true;
            }
            while(st.top() != '('){
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}

int main(){
    string str = "((a+b)+(a+b))";
    cout << findDub(str)<< endl;
}