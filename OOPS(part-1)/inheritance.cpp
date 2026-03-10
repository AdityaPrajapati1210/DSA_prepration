#include<iostream>
using namespace std;

class Animal {

    public:
    string color;

    void eat(){
        cout << "Eats..."<<endl;
    }

    void breathe(){
        cout << "Breathe.."<<endl;
    }
};

class Fish : public Animal{
    public:
    int fins;

    void swim(){
        cout << "swim.."<<endl;
    }
};


int main(){
    Fish cow;
    cow.swim();
    cow.breathe();
    
}