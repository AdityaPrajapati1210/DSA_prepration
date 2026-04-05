#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }


    int main(){
        queue<int>q;
        for (int i=1;i<10;i++){
            q.push(i);
        }
        reverseQueue(q);

        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;

    }