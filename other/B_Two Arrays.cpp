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
ll const MOD=1'000'000'007;

ll N;
ll a[10000], b[10000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,N) cin>>b[i];

    ll sum=0;
    rep(i,N) sum+=b[i]-a[i];
    ll cnt=0;
    rep(i,N){
        if(a[i]<b[i]){
            cnt+=(b[i]-a[i]+1)/2*2;
        }else{
            cnt+=b[i]-a[i];
        }
    }
    if(cnt<=sum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}