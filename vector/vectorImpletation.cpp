#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>vec = {1,2,3,4};
    cout << "size : "<<vec.size() <<endl;
    cout << "capacity : "<<vec.capacity() <<endl;

    vec.push_back(5);    //capasity is full then created adouble capacit vector
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);    
    vec.push_back(9);       //their 8 size vec is also full then created a 16 size double of 8 is created.
    
    cout << "size : "<<vec.size() <<endl;
    cout << "capacity : "<<vec.capacity() <<endl;
}