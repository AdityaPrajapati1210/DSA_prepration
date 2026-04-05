#include<iostream>
#include<stack>
using namespace std;
stack<int> st1;
stack<int> st2;

void push(int data){
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    st1.push(data);
    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
}

void popp(){
    st1.pop();
}


void print(){
    while(!st1.empty()){
        cout << st1.top()<<" ";
        st1.pop();
    }
}
int main(){

    push(10);
    push(103);
    push(130);
    push(30);
    popp();
    print();





}