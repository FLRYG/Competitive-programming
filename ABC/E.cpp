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
typedef pair<ll,int> P;

ll N;
ll A[2000];
bool chk[2000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    fill(chk,chk+N,false);
    ll ans1=0;
    rep(i,N){
        if(chk[i]) continue;
        ll x=A[i];
        ll res=0;
        ll index;
        chk[i]=true;
        rep(j,N){
            if(chk[j]) continue;
            ll y=A[j];
            res=max(res,(x+y)*abs(i-j));
            if(res==(x+y)*abs(i-j)) index=j;
        }
        chk[index]=true;
        ans1+=res;
    }

    fill(chk,chk+N,false);
    ll ans2=0;
    for(int i=N-1;i>=0;i--){
        if(chk[i]) continue;
        ll x=A[i];
        ll res=0;
        ll index;
        chk[i]=true;
        rep(j,N){
            if(chk[j]) continue;
            ll y=A[j];
            res=max(res,(x+y)*abs(i-j));
            if(res==(x+y)*abs(i-j)) index=j;
        }
        chk[index]=true;
        ans2+=res;
    }

    /*ll ans1=0;
    priority_queue<P> que1;
    rep(i,N/2) que1.push(P(A[i],i));
    if(N&1) que1.push(P(A[N/2+1],N/2+1));
    rep(i,N/2){
        P p=que1.top();
        ans1+=(A[N-i-1]+p.first)*abs(N-i-1-p.second);
        que1.pop();
    }

    ll ans2=0;
    priority_queue<P> que2;
    rep(i,N/2) que2.push(P(A[N-i-1],N-i-1));
    if(N&1) que2.push(P(A[N/2+1],N/2+1));
    rep(i,N/2){
        P p=que2.top();
        ans2+=(A[i]+p.first)*abs(i-p.second);
        que2.pop();
    }*/

    cout<<ans1<<' '<<ans2<<endl;
    ll ans=max(ans1,ans2);
    cout<<ans<<endl;
}