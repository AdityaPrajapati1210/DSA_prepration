#include<iostream>
using namespace std;


class Student {
    string name;
    float cgpa;
    public:


    // setters

    void setName(string name){
        this->name = name;
    };

    void setCgpa(float cgpa){
        this->cgpa = cgpa;
    }

    // getters
    string getName(){
        return this->name;
    }

    float getCgpa(){
        return this->cgpa;
    }


};



int main(){
    Student s1;
    s1.setName("Aditya");
    s1.setCgpa(7.89);
    cout<< s1.getCgpa() << endl;

   
    
}