#include<iostream>
#include<queue>
using namespace std;

class Stack{
    public:
    queue<int>q1;
    queue<int>q2;

    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        q1.pop();

    }
    void top(){
        q1.front();
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.pop();
    s.top();
}