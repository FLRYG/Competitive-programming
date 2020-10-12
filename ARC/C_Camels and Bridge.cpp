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

int N,M;
int w[8];
int l[100000];
int v[100000];

int pow(int x, int n){
    rep(i,n-1) x*=x;
    return x;
}

int main(){
    cin>>N>>M;
    rep(i,N) cin>>w[i];
    rep(i,M) cin>>l[i]>>v[i];

    int W=0;
    rep(i,N) W=max(W,w[i]);
    rep(i,M){
        if(v[i]<W){
            cout<<-1<<endl;
            return 0;
        }
    }

    sort(w,w+N);

    ll ans=0;
    rep(i,M){
        ll x=0;
        ll cnt=0;
        rep(j,N){
            if(x+w[i]<=v[i]) x+=w[i];
            else{
                cnt++;
                x=w[i];
            }
        }
        ans=max(ans,cnt*l[i]);
    }

    cout<<ans<<endl;
}