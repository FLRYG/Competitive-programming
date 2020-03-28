#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll X,Y;
ll A,B,C;
priority_queue<ll> p,q,pqr;

int main(){
    cin>>X>>Y>>A>>B>>C;
    rep(i,A){ll x; cin>>x; p.push(x);}
    rep(i,B){ll x; cin>>x; q.push(x);}
    rep(i,C){ll x; cin>>x; pqr.push(x);}

    rep(i,X){pqr.push(p.top()); p.pop();}
    rep(i,Y){pqr.push(q.top()); q.pop();}

    ll ans=0;
    for(int i=0;i<X+Y;i++){
        ans+=pqr.top();
        pqr.pop();
    }

    cout<<ans<<endl;
}

