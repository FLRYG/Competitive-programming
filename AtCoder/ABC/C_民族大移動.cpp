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

ll N,D,K;
ll L[10000], R[10000];
ll S[100], T[100];
ll ans[100];

int main(){
    cin>>N>>D>>K;
    rep(i,D) cin>>L[i]>>R[i];
    rep(i,K) cin>>S[i]>>T[i];

    rep(d,D){
        rep(i,K){
            if(S[i]!=T[i]){
                if(L[d]<=S[i] && S[i]<=R[d]){
                    if(L[d]<=T[i] && T[i]<=R[d]){
                        S[i]=T[i];
                        ans[i]=d+1;
                    }else{
                        if(S[i]<T[i]) S[i]=R[d];
                        else S[i]=L[d];
                    }
                }
            }
        }
    }

    rep(i,K) cout<<ans[i]<<endl;
}