#include<iostream>
using namespace std;

class User {
    int id;
    string password;

    public:
    string username;

    User(int id){
        this->id = id;          
    }

    // setter
    void setPass(string password){
        this->password = password;
    }

    // getter
    void getPas(){
        cout << password <<endl;
    }
};

int main(){
    User a1(123);
    a1.setPass("abc@123");
    a1.getPas();

}