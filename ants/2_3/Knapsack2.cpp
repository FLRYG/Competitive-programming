#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,W;
int w[100];
int v[100];

int dp1[100+1][10000+1];
void solve1(){
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp1[i][j]=dp1[i+1][j];
            }else{
                dp1[i][j]=max(dp1[i+1][j],dp1[i+1][j-w[i]]+v[i]);
            }
        }
    }
}

int dp2[100+1][10000+1];
void solve2(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp2[i+1][j]=dp2[i][j];
            }else{
                dp2[i+1][j]=max(dp2[i][j],dp2[i][j-w[i]]+v[i]);
            }
        }
    }
}

int dp3[100+1][10000+1];
void solve3(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            dp3[i+1][j]=max(dp3[i][j],dp3[i+1][j]);
            if(j+w[i]<=W){
                dp3[i+1][i+w[i]]=max(dp3[i+1][j+w[i]],dp3[i][j]+v[i]);
            }
        }
    }
}

int main(){
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }

    solve1();
    cout<<dp1[0][W]<<endl;

    solve2();
    cout<<dp2[N][W]<<endl;

    solve3();
    cout<<dp3[N][W]<<endl;
}