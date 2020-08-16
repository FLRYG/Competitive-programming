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
//int const INF=1001001001;
ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll P[5001];
ll C[5001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>P[i];
    repn(i,N) cin>>C[i];

    ll ans=-INF;
    repn(idx,N){
        ll sum=C[idx];
        ll cnt=1;
        for(int pos=P[idx];pos!=idx;pos=P[pos]){
            sum+=C[pos];
            cnt++;
        }
        
        ll res=0;
        if(sum>0) res=K/cnt*sum;
        ll roop=K%cnt;
        if(roop==0) roop=cnt;
        //cout<<idx<<' '<<sum<<' '<<cnt<<' '<<res<<endl;
        for(int pos=P[idx],i=0;i<roop;pos=P[pos],i++){
            res+=C[pos];
            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
}

/*
ll N,K;
ll P[5001];
ll C[5001];
bool chk[5001];
ll maxi[5001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>P[i];
    repn(i,N) cin>>C[i];

    ll ans=-INF;
    repn(idx,N){
        ll res=0;
        ll pos=idx;
        ll cnt=0;
        ll sup=-INF;
        fill(chk,chk+N+1,false);
        repn(i,K){
            pos=P[pos];
            //cout<<idx<<' '<<pos<<endl;
            if(chk[pos]){
                ll m=K/cnt;
                if(res>0){
                    res=m*res+maxi[K%cnt];
                    //cout<<res<<endl;
                    ans=max(ans,res);
                }
                break;
            }
            cnt++;
            chk[pos]=true;
            res+=C[pos];
            if(res>sup) sup=res;
            maxi[cnt]=sup;
            //cout<<res<<endl;
            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
}
*/