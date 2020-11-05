#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%13;
    return mpow(x*x%13,n/2)%13;
}

string S;
ll length;
ll dp[13];

int main(){
    cin>>S;
    length=S.size();

    for(int i=length-1;i>=0;i--){
        ll m[13];
        fill(m,m+13,0);
        ll p10=mpow(10,(length-1)-i);
        if(S[i]!='?'){
            ll x=S[i]-'0';
            m[x*p10%13]++;
        }else{
            rep(j,10){
                m[j*p10%13]++;
            }
        }
        ll res[13];
        fill(res,res+13,0);
        if(i==length-1){
            rep(i,13){
                res[i]=m[i];
            }
        }else{
            rep(i,13){
                rep(j,13){
                    if(m[i]!=0 && dp[j]!=0) res[(i+j)%13]+=(m[i]*dp[j])%MOD;
                }
            }
        }
        rep(i,13){
            dp[i]=res[i];
        }
    }

    ll ans=dp[5]%MOD;
    cout<<ans<<endl;
}