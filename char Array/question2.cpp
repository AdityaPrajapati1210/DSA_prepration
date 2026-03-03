// Question2:You are given twos trings s1 and s2 of equal length.A string swap is an operation where you choose  two indices in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make boths tring sequal by performing at most one string swap on exactly oneo fthe strings.Otherwise,return false.
// Example:Input:s1="bank",s2="kanb"Output:true Explanation:For example,swap the first character withthe last character of s2 to make"bank".

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1 = "bank";
    string s2 = "kanb";

    int same =0,diff =0;

    if(s1 == s2){
        cout<< "true"<<endl;
        return 0;
    }else{
        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }
        if(diff == 2){
            cout<< "true"<<endl;
        }else{
            cout<< "false"<<endl;
        }
    }


}