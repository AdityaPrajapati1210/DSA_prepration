#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec1;
    vector<int>vec2 = {1,3,4,5,6};
    vector<int>vec3(6,0);



    cout << vec1.size() << endl;
    cout << vec2.size() << endl;
    cout << vec3.size() << endl;
}