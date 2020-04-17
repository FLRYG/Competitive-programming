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

ll A,B,Q;
ll s[100001];
ll t[100001];
ll x[100000];

int main(){
    cin>>A>>B>>Q;
    repn(i,A) cin>>s[i];
    repn(i,B) cin>>t[i];
    rep(i,Q) cin>>x[i];

    rep(i,Q){
        ll a1=0, a2=A;
        while(a2-a1>1){
            ll c=(a1+a2)/2;
            if(x[i]<s[c]) a2=c;
            else a1=c;
        }
        ll b1=0, b2=B;
        while(b2-b1>1){
            ll c=(b1+b2)/2;
            if(x[i]<t[c]) b2=c;
            else b1=c;
        }

        ll num[4]={a1,a2,b1,b2};
        ll ans=100100100100100;
        rep(j,4) rep(k,2){
            if(j<=1){
                if(num[j]==0 || num[k+2]==0) continue;
                ans=min(ans,abs(x[i]-s[num[j]])+abs(s[num[j]]-t[num[k+2]]));
            }else{
                if(num[j]==0 || num[k]==0) continue;
                ans=min(ans,abs(x[i]-t[num[j]])+abs(t[num[j]]-s[num[k]]));
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}