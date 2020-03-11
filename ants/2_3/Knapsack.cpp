#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,W;
int w[100];
int v[100];
int dp[100+1][10000+1];

int rec(int i,int j){
    int res;
    if(dp[i][j]>=0){
        return dp[i][j];
    }

    if(i==N){
        return 0;
    }else if(w[i]>j){
        res=rec(i+1,j);
    }else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }

    return dp[i][j]=res;
}

int main(){
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,W);
}