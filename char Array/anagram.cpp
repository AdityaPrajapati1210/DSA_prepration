#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void lower(string &str){
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
}

int main(){
    string str1 = "anagram";
    string str2 = "gramana";

    if(str1.length() != str2.length()) return false;

    lower(str1);
    lower(str2);

    int freq[26] = {0};

    for(int i = 0; i < str1.length(); i++){
        freq[str1[i] - 'a']++;
    }

    for(int i = 0; i < str2.length(); i++){
        if(freq[str2[i] - 'a'] == 0){
            cout << "Not anagram" << endl;
            return 0;
        }
        freq[str2[i] - 'a']--;
    }

    cout << "Anagram" << endl;
}