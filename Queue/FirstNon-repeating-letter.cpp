#include<iostream>
#include<queue>
#include<string>
using namespace std;


void Firstrepeating(string str,string &ans){
    int n = str.length();
    queue<char>q;
    int freq[26] ={0};
    for(int i=0;i<n;i++){
        char ch  = str[i];
        q.push(ch);
        freq[ch-'a']++;
        if(freq[q.front() -'a'] == 1){
            ans += q.front();
        }else{
            while(!q.empty() && freq[q.front()- 'a']  > 1){
                q.pop();
            }
            if(q.empty()){
                ans += "-1";
            }else{
                ans+=q.front();
            }    
        }
    }
}

int main(){
    string str = "aabccxb";
    string ans = "";

    Firstrepeating(str,ans);
    cout << ans<<endl;

}