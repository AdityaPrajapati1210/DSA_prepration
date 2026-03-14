#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;

};

class Student : public Person{
    public:
    int studentID;

    Student(string name,int age,int studentID){
        this->name = name;
        this->age  = age;
        this->studentID = studentID;
    }

    void displayStudentInfo(){
        cout <<"Name : "<< this->name <<endl;
        cout <<"Age : "<< this->age <<endl;
        cout <<"StudentID : "<< this->studentID <<endl;
    }
};


int main(){
    Student s1("aditya",20,111);
    s1.displayStudentInfo();
}