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
typedef pair<ll,ll> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll H,W,M;
ll h[300000];
ll w[300000];

int main(){
    cin>>H>>W>>M;
    rep(i,M) cin>>h[i]>>w[i];

    vector<ll> cnth(H),cntw(W);
    rep(i,M){
        cnth[h[i]-1]++;
        cntw[w[i]-1]++;
    }

    ll suph=0,supw=0;
    vector<ll> idxh,idxw;
    rep(i,H){
        if(cnth[i]>suph){
            suph=cnth[i];
            idxh.clear();
            idxh.push_back(i);
        }else if(cnth[i]==suph){
            idxh.push_back(i);
        }
    }
    rep(i,W){
        if(cntw[i]>supw){
            supw=cntw[i];
            idxw.clear();
            idxw.push_back(i);
        }else if(cntw[i]==supw){
            idxw.push_back(i);
        }
    }

    map<P,ll> m;
    rep(i,M) m[P(h[i]-1,w[i]-1)]++;

    ll ans=suph+supw-1;
    rep(i,idxh.size()){
        rep(j,idxw.size()){
            if(m[P(idxh[i],idxw[j])]==0){
                ans++;
                goto a;
            }
        }
    }
    a:;

    cout<<ans<<endl;
}