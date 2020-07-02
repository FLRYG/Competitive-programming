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

ll N;
ll x[100], y[100];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    ll ans=0;
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                ll a=x[j]-x[i], b=y[j]-y[i];
                ll c=x[k]-x[i], d=y[k]-y[i];
                ll S=abs(a*d-b*c);
                if(S%2==0 && S!=0) ans++;
            }
        }
    }

    cout<<ans<<endl;
}