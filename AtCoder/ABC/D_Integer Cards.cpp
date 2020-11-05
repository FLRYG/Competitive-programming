#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

typedef pair<ll,ll> P;
ll N,M;
priority_queue<P> ABC;

int main(){
    cin>>N>>M;
    rep(i,N){
        ll a;
        cin>>a;
        ABC.push(P(a,1));
    }
    rep(i,M){
        ll b,c;
        cin>>b>>c;
        ABC.push(P(c,b));
    }

    ll ans=0;
    while(N>0){
        ll c=ABC.top().first;
        ll b=ABC.top().second;
        while(b>0){
            ans+=c;
            b--;
            N--;
            if(N<=0) break;
        }
        ABC.pop();
    }

    cout<<ans<<endl;
}