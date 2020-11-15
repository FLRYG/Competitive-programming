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

ll N,K;
ll T[8][8];

int main(){
    cin>>N>>K;
    rep(i,N) rep(j,N) cin>>T[i][j];

    vector<ll> v(N-1);
    rep(i,N-1) v[i]=i+1;

    ll ans=0;
    do{
        ll res=0;
        res+=T[0][v[0]];
        rep(i,N-2){
            res+=T[v[i]][v[i+1]];
        }
        res+=T[v[N-2]][0];
        if(res==K) ans++;
    }while(next_permutation(v.begin(),v.end()));
    
    cout<<ans<<endl;
    return 0;
}