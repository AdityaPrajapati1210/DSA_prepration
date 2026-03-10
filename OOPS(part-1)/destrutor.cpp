#include<iostream>
using namespace std;

class Car {
    public:
    string model;
    string color;
    int *milage;

    Car(){
        cout << "Object is created" << endl;
    }

    Car(string model,string color){
        cout<<"uffff garmi....\n";
        this->model = model;
        this->color = color;
        milage = new int;
        *milage = 12;
    }

    ~Car(){
        cout << "destructor runs..."<<endl;
        if(milage != NULL){
            delete milage;
            milage = NULL;
        }
    }

};

int main(){
    Car c1("chutiya" , "white");
    *c1.milage = 32;
    
}