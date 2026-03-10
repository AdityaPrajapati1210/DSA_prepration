#include<iostream>
using namespace std;

class Animal {
    public:
    void eat(){
        cout << "Eats..."<<endl;
    }
};

class Fish : public Animal{
    public:
    void swim(){
        cout << "swim.."<<endl;
    }
};

class Whale : public Animal{
    public:
    void size(){
        cout << "Big"<<endl;
    }
};


int main(){
    Whale a;
    a.size();
    a.eat();
    Whale b;
    b.size();
    b.eat();
}