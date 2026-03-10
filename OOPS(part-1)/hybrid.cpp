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

class abc : public Whale{
    public:
    void sleep(){
        cout << "sleep" <<endl;
    }
};


int main(){
    Whale a;
    a.size();
    a.eat();
    Whale b;
    b.size();
    b.eat();
    abc meow;
    meow.sleep();
    meow.eat();
}