// Question1:Count how many times lowercase vowel so ccurred in a String entered by the user.


#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "";
    cout <<"Enter a string : ";
    getline(cin,str);
    
    int count = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == 'a' |str[i] == 'e' ||str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u'  ){
            count++;
        }
    }

    cout << "Lowercase vowel : "<< count<<endl;
}