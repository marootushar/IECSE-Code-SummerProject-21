#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int res;

void dfs(int rootIndex, int tree[], int height[]){
    int left = rootIndex*2;
    int right = rootIndex*2 + 1;
    if(tree[left]!=-1){
        dfs(left, tree, height);
    }
    //right child
    if(tree[right] != -1){
        dfs(right, tree, height);
    }
    if(tree[left]!=-1 || tree[right] != -1){
        height[rootIndex]=1+max(height[left], height[right]);
        res=max(res, height[left]+height[right]+1);
    }

}

int main(){
    int n, i, j;
    int tree[10000];
    tree[1]=1;
    cin>>n;
    for(i=1; i< 10000; i++) tree[i]=-1;
    int height[1001];
    tree[1]=1;
    for(i=1; i<1001; i++) height[i]=1;
    for(i=0; i<n-1; i++){
        int x, y;
        char c;
        cin>>x>>y>>c;
        for(j=1; j<2002; j++){
            if(tree[j]==x){
                    //cout<<j<<endl;
                if(c=='L'){
                    tree[2*j]=y;
                    //cout<<2*j<<endl;
                }
                else{
                    tree[2*j + 1]=y;
                     //cout<<2*j + 1<<endl;
                }
                break;
            }
        }
    }
    dfs(1, tree, height);
    cout<<res;

}