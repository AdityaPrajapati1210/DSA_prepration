#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[] = {'a','v','g','f'};
     int n = sizeof(str)/sizeof(char);
    



    for(int i=0;i<n;i++){
        if(str[i] >= 'a' && str[i] <='z'){
            str[i] = str[i]-'a'+'A';
        }
    }

    cout << str <<endl;



    //  char word[50];
    //  cin >> word;

    // cin.getline(word , 34);

    //  cout<< word << endl;
    //  cout<< strlen(word) << endl;


}