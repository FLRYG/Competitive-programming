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

ll H,W;

int main(){
    cin>>H>>W;

    ll ans=INF;
    repn(a,W-1){
        ll s=a*H;
        ll t=(H/2)*(W-a);
        ll u=((H+1)/2)*(W-a);
        ll res=max(s,max(t,u))-min(s,min(t,u));
        ans=min(ans,res);

        if(a<=W-2){
            t=(W-a)/2*H;
            u=(W-a+1)/2*H;
            res=max(s,max(t,u))-min(s,min(t,u));
            ans=min(ans,res);
        }
    }

    repn(a,H-1){
        ll s=a*W;
        ll t=(W/2)*(H-a);
        ll u=((W+1)/2)*(H-a);
        ll res=max(s,max(t,u))-min(s,min(t,u));
        ans=min(ans,res);

        if(a<=H-2){
            t=(H-a)/2*W;
            u=(H-a+1)/2*W;
            res=max(s,max(t,u))-min(s,min(t,u));
            ans=min(ans,res);
        }
    }

    cout<<ans<<endl;
}