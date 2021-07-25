#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int price[n];
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
       stack<int> stk;
       vector<int> res;
       for(int i=0; i<n; i++){
           while(!stk.empty() && price[i]>=price[stk.top()]){
               stk.pop();
           }
           if(stk.empty()){
               res.push_back(i+1);
           }
           else{
               res.push_back(i - stk.top());
           }
           stk.push(i);
       }
    for(int i : res) cout<<i<<" ";
    cout<<endl;
}