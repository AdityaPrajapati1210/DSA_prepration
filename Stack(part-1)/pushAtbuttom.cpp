#include<iostream>
#include<stack>
using namespace std;


void push_buttom(stack<int> &s,int data){
    if(s.empty()) {
        s.push(data);
        return;
    }

    int top = s.top();
    s.pop();
    push_buttom(s ,data);
    s.push(top);
}

void print(stack<int> s){
    while(!s.empty()){
        cout <<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    push_buttom(s,1);
    s.pop();
    print(s);
}