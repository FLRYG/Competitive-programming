#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T;

int main(){
    cin>>T;

    vector<ll> ans(T);
    rep(t,T){
        ll N,A,B;
        cin>>N>>A>>B;
        ll n=A+B-1;

        if(n>=N){
            ans[t]=0;
            continue;
        }

        ll res=0;
        res+=(N-A+1)*(N-A+1)%MOD*(N-B+1)%MOD*(N-B+1)%MOD;
        res-=(n-A+1)*(n-A+1)%MOD*(n-B+1)%MOD*(n-B+1)%MOD*(N-n+1)%MOD;
        res%=MOD;
        if(res<0) res+=MOD;

        ans[t]=res;
    }

    rep(i,T) cout<<ans[i]<<endl;
}

// int T;

// int main(){
//     cin>>T;

//     vector<ll> ans(T);
//     rep(t,T){
//         ll N,A,B;
//         cin>>N>>A>>B;

//         ll res=0;
//         res+=(N-A-B)*(N-A-B+1)%MOD*(N-B+1)%MOD;
//         res-=(N-B+1)*((N-A-B)*(N-A-B+1)/2)%MOD;
//         res=(res+MOD)%MOD;

//         ans[t]=res;
//     }

//     rep(i,T) cout<<ans[i]<<endl;
// }