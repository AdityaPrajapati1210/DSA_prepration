#include<iostream>
#include<vector>

using namespace std;


template <class T>  //use for multiple datatype use in same code or class
class Stack{
    vector<int>s;
    // int top = -1;
    public:
    void push(int data){
        s.push_back(data);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        s.pop_back();
    }

    bool isEmpty(){
        if(s.size() == 0){
            return true;
        }else{
            return false;
        }
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return s[s.size()-1];
    }

    void print(){
        while(!isEmpty()){
            int lastindex = s.size()-1;
            cout<<s[lastindex]<<endl;
            s.pop_back();
        }
    }
};


int main(){
    Stack<int> s;
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.pop();
    cout << s.top();

    s.print();
}