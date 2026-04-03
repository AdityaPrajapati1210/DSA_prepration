#include<iostream>
#include<stack>
using namespace std;


void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void push_buttom(stack<int>&st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    push_buttom(st,val);
    st.push(temp);
}


void reverseSt(stack<int>&st){
    
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    reverseSt(st);
    push_buttom(st,temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    reverseSt(st);
    print(st);
}