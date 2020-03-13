#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,W;
int w[100];
int v[100];
int dp[100+1][10000+1];

void init(){ memset(dp,-1,sizeof(dp)); }

void solve1(){
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp[i][j]=dp[i+1][j];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
}

int main(){
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }

    init();
    solve1();
    cout<<dp[0][W]<<endl;    
}