#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

int N;
ll dp[101][4][4][4];

int main(){
    cin>>N;

    dp[0][3][3][3]=1;

    rep(i,N){
        rep(j,4){
            rep(k,4){
                rep(l,4){
                    if(dp[i][j][k][l]==0) continue;
                    rep(a,4){
                        if(k==0 && l==1 && a==2) continue;
                        if(k==1 && l==0 && a==2) continue;
                        if(k==0 && l==2 && a==1) continue;
                        if(j==0 && k==1 && a==2) continue;
                        if(j==0 && l==1 && a==2) continue;
                        dp[i+1][k][l][a]+=dp[i][j][k][l];
                        dp[i+1][k][l][a]%=MOD;
                    }
                }
            }
        }
    }

    ll ans=0;
    rep(i,4){
        rep(j,4){
            rep(k,4){
                ans+=dp[N][i][j][k];
            }
        }
    }
    ans%=MOD;
    cout<<ans<<endl;
}