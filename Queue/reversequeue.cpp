#include<iostream>
#include<queue>
using namespace std;

 void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        queue<int>first;
        
        for(int i=0;i<(n+1)/2;i++){
            first.push(q.front());
            q.pop();
        }
        
        while(!first.empty()){
            int temp = first.front();
            q.push(temp);
            first.pop();
            if(first.empty()){
                break;
            }
            temp = q.front();
            q.push(temp);
            q.pop();
        }
    }


    int main(){
        queue<int>q;
        for (int i=1;i<10;i++){
            q.push(i);
        }
        rearrangeQueue(q);

        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;

    }