#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
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
typedef pair<ll,ll> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll P[5001];
ll C[5001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>P[i];
    repn(i,N) cin>>C[i];

    ll ans=-LINF;
    repn(n,N){
        cout<<n<<' ';
        vector<ll> chk(N+1,0);
        vector<ll> idx(N+1);
        vector<ll> scr(N+1,0);
        ll pos=n;
        ll cnt=0;
        ll score=-LINF;
        ll tmp=0;
        ll k=K;
        while(chk[P[pos]]==0 && k>0){
            cnt++; k--;
            pos=P[pos];
            chk[pos]=cnt;
            idx[cnt]=pos;
            tmp+=C[pos];
            scr[cnt]=tmp;
            score=max(score,tmp);
        }
        cout<<score<<' '<<k<<' ';
        if(k==0){
            ans=max(ans,score);
            continue;
        }
        // k=K;
        // ll score2=scr[idx[min(k,chk[P[pos]]-1)]];
        // k-=min(k,idx[chk[P[pos]]-1]);
        // score2+=k/(cnt-chk[P[pos]]+1)*(scr[idx[cnt]]-scr[idx[chk[P[pos]]-1]]);
        // cout<<score2<<' ';
        // cout<<k%(cnt-chk[P[pos]]+1)<<' ';
        // for(ll j=0;j<=k%(cnt-chk[P[pos]]+1);j++){
        //     score=max(score,score2+scr[j+idx[chk[P[pos]]-1]]-scr[idx[chk[P[pos]]-1]]);
        // }
        // ans=max(ans,score);
        k=K;
        tmp=scr[min(k,chk[P[pos]]-1)];
        cout<<tmp<<' '<<chk[P[pos]];
        k-=min(k,chk[P[pos]]-1);
        tmp+=k/(cnt-chk[P[pos]]+1)*(scr[cnt]-scr[chk[P[pos]-1]]);
        for(ll j=0;j<=k%(cnt-chk[P[pos]]+1);j++){
            score=max(score,tmp+scr[j+chk[P[pos]]-1]-scr[chk[P[pos]]-1]);
        }
        ans=max(ans,score);
        cout<<score<<endl;
    }

    cout<<ans<<endl;

    return 0;
}

// int main(){
//     cin>>N>>K;
//     repn(i,N) cin>>P[i];
//     repn(i,N) cin>>C[i];

//     ll ans=-INF;
//     repn(idx,N){
//         ll sum=C[idx];
//         ll cnt=1;
//         for(int pos=P[idx];pos!=idx;pos=P[pos]){
//             sum+=C[pos];
//             cnt++;
//         }
        
//         ll res=0;
//         if(sum>0) res=K/cnt*sum;
//         ll roop=K%cnt;
//         if(roop==0) roop=cnt;
//         //cout<<idx<<' '<<sum<<' '<<cnt<<' '<<res<<endl;
//         for(int pos=P[idx],i=0;i<roop;pos=P[pos],i++){
//             res+=C[pos];
//             ans=max(ans,res);
//         }
//     }
//     cout<<ans<<endl;
// }

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