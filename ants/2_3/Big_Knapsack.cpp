#include <iostream>
#include <algorithm>
using namespace std;

const int INF=1001001001;

int N,W;
int w[100];
int v[100];
int dp[100+1][100*100+1];

int main(){
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }
    
    fill(dp[0],dp[0]+100*100+1,INF);
    dp[0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=100*100;j++){
            if(j<v[i]){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
            }
        }
    }

    int res=INF;
    for(int i=0;i<100*100+1;i++){
        if(dp[N][i]<=W) res=i;
    }
    cout<<res;
}