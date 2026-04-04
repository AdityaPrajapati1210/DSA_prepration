#include<iostream>
#include<stack>
using namespace std;


void nextGreator(int *arr,int size,int *ans){
    stack<int>st;
    for(int i= size-1;i>= 0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
}


void print(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {5,9,3,9,4,8,2,3};
    int size = sizeof(arr)/sizeof(int);

    int ans[size] = {-1};
    nextGreator(arr,size,ans);

    print(arr,size);
    print(ans,size);
}