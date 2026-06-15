#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;

    pq.push(10);
    pq.push(13);
    pq.push(132);
    pq.push(1);
    pq.push(11);
    pq.push(3);

    while(!pq.empty()){
        cout <<" Top : "<<pq.top()<<endl;
        pq.pop();
    }

}