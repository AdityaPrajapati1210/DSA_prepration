#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main(){
    list<int> ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(10);

    list<int>::iterator itr;

    for(itr=ll.begin();itr!= ll.end();itr++){
        cout << *itr <<"->";
    }
    cout<<"NULL"<<endl;
}