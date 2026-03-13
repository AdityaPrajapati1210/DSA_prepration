#include<iostream>
using namespace std;

class BackAccount{

    int accountNumber;
    int balance = 0;

    public:
    void deposit(int amount){
        this->balance += amount;
        cout<<"Successfully Deposite :"<<amount<<endl;
    }

    void withdraw(int amount){
        if(this->balance > amount){
            this->balance -= amount;
            cout<<"Successfully Withdraw"<<endl;
        }else{
            cout<<"Not enough Amount"<<endl;
        }
    }

    void getBalance(){
        cout <<"Your remaining balance : "<<this->balance <<endl;
    }
};


int main(){
    BackAccount a;
    a.deposit(100);
    a.getBalance();
    a.withdraw(50);
}