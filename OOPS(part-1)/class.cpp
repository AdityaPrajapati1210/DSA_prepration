#include<iostream>
using namespace std;


class Student {
    public:
    string name;
    float cgpa;

    void getPercentage(){
        cout << (cgpa *10) << endl;
    }
};
//  create a class for insta user which have propperties like id , username  , password , bio  and its function.


class User {
    public:
    int id;
    string username;
    string password;
    string bio;


    void deactivate(){
        cout << "Delete Account" << endl;
    };

    void ChangeBio(string newBio){
        bio = newBio;
    }

    void show(){
        cout << id <<endl;
        cout << username << endl;
        cout << bio << endl;
    }
};


int main(){
    // Student s1;

    // s1.name = "Aditya";
    // s1.cgpa = 7.089;
    // s1.getPercentage();

    User a;
    a.username = "prajapati";
    a.id = 123;
    a.password = "abc@123";
    a.bio = "Focus on goal not hole!";
    a.show();
    
    a.ChangeBio(" is my crush!");
    a.show();
    
}