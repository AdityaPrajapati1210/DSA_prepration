#include<iostream>
#include<queue>
#include<string>
using namespace std;


class Student{
    public:
    string name;
    int marks;

    Student(string name ,int marks){
        this->name = name;
        this->marks = marks;
    }

    // operator overloading
    bool operator < (const Student &obj)const{
        return this->marks < obj.marks;
    }
};
int main(){
    priority_queue<Student>pq;
    pq.push(Student("Aditya" , 100));
    pq.push(Student("Aditi" , 300));
    pq.push(Student("abhishek" , 400));
    pq.push(Student("karan" , 200));
    while(!pq.empty()){
        cout << "Name : "<<pq.top().name<<" ,marks : "<<pq.top().marks<<endl;
        pq.pop();
    }
}