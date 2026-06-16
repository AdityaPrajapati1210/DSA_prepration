#include<iostream>
#include<queue>
#include<string>
using namespace std;


struct Compare{
    bool operator () (pair<string ,int>p1 , pair<string,int>p2){
        return p1.second < p2.second;
    }
};

// class Student{
//     public:
//     string name;
//     int rank;


//     Student(string name, int rank){
//         this->name = name;
//         this->rank = rank;
//     }
// };

int main(){
    priority_queue<pair<string,int>>pq;

    pq.push(make_pair("Adiyta" ,100));
    pq.push(make_pair("Adiyta" ,700));
    pq.push(make_pair("Adiyta" ,300));
    pq.push(make_pair("Adiyta" ,200));

    while(!pq.empty()){
        cout << pq.top().first <<"   "<<pq.top().second<<endl;
        pq.pop();
    }

}