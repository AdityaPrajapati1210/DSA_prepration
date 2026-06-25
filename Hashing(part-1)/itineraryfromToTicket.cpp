#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;



vector<string>findroot(vector<pair<string,string>>fromTo){
    int n = fromTo.size();
    set<string>st;
    unordered_map<string,string>mp;

    for(auto i : fromTo){
        mp[i.first] = i.second;
        st.insert(i.second);
    }
    // find the starting point

    string starting;
    for(auto i : fromTo){
        if(st.find(i.first) == st.end()){
            starting = i.first;
            break;
        }
    }
    string destination = mp[starting];
    vector<string>root;
    for(int i = 0;i<n;i++){
        root.push_back(starting);
        if(mp.find(destination) == mp.end()){
            root.push_back(destination);
            break;
        }
        starting = destination;
        destination = mp[starting];
    }

    return root;


}

int main(){
    vector<pair<string,string>>fromTo = {
        make_pair("mumbai","delhi"),
        make_pair("chennai","bengaluru"),
        make_pair("goa","chennai"),
        make_pair("delhi","goa")
    };
    

    vector<string> root = findroot(fromTo);

    for(auto i : root){
        cout << i <<" -> ";
    }
    cout<<endl;
}