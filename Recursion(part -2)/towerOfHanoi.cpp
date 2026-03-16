#include<iostream>
using namespace std;

void towerOfHanoi(int n,string src,string helper,string dest){
    if(n==1){
        cout<<"transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,helper);
   
    cout<<" transfer disk "<<n<<" from "<<src<<" to "<<helper<<endl;
    towerOfHanoi(n-1,helper,src,dest);
}
int main(){
    int n=4;
    towerOfHanoi(4,"A","B","C");
    return 0;
}