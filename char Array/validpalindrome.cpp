#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[] = "racecar";
    int n = strlen(str);
    int st =0;
    int end = n-1;
    bool isfound = false;
    while(st <= end){
        if(str[st] != str[end]){
            isfound = true;
            break;
        }
        st++;
        end--;
    }
    
    if(!isfound){
        cout << "Valid"<<endl;
    }else{
        cout << "Not Palindrome!"<<endl;
    }
    return 0;




}