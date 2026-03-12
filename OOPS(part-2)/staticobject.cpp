#include<iostream>
using namespace std;

class baby {
    public:
    baby(){
        cout<<"Constructor"<<endl;
    }
    ~baby(){
        cout<<"Destructor"<<endl;
    }
};


int main(){
    int i=0;
    if(i ==0){
        static baby babu;
    }

    cout <<"Ending..."<<endl;
}