#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;

int main(){
    cin>>N;
    vector<ll> r,g,b;
    rep(i,2*N){
        ll a;
        char c;
        cin>>a>>c;
        if(c=='R') r.push_back(a);
        if(c=='G') g.push_back(a);
        if(c=='B') b.push_back(a);
    }
    
    if(r.size()%2==0 && g.size()%2==0 && b.size()%2==0){
        cout<<0<<endl;
        return 0;
    }

    vector<ll> x,y,z;
    if(r.size()%2==1) x=y, y=r;
    if(g.size()%2==1) x=y, y=g;
    if(b.size()%2==1) x=y, y=b;
    if(r.size()%2==0) z=r;
    if(g.size()%2==0) z=g;
    if(b.size()%2==0) z=b;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());

    ll ans=LINF;
    rep(i,x.size()){
        int l=0, r=y.size()-1;
        while(r-l>1){
            int m=(l+r)/2;
            if(x[i]>=y[m]) l=m;
            else r=m;
        }
        ans=min(ans,min(abs(x[i]-y[l]),abs(x[i]-y[r])));
        // cout<<y[l]<<' '<<x[i]<<' '<<y[r]<<endl;
    }

    if(z.size()==0){
        cout<<ans<<endl;
        return 0;
    }

    vector<ll> z1=z;
    ll s1=INF, si1;
    rep(i,x.size()){
        int l=0, r=z1.size()-1;
        while(r-l>1){
            int m=(l+r)/2;
            if(x[i]>=z1[m]) l=m;
            else r=m;
        }
        if(abs(x[i]-z1[l])<s1){
            s1=abs(x[i]-z1[l]);
            si1=l;
        }
        if(abs(x[i]-z1[r])<s1){
            s1=abs(x[i]-z1[r]);
            si1=r;
        }
    }

    ll t1=INF, ti1;
    rep(i,y.size()){
        int l=0, r=z1.size()-1;
        while(r-l>1){
            int m=(l+r)/2;
            if(y[i]>=z1[m]) l=m;
            else r=m;
        }
        if(abs(y[i]-z1[l])<t1){
            t1=abs(y[i]-z1[l]);
            ti1=l;
        }
        if(abs(y[i]-z1[r])<t1){
            t1=abs(y[i]-z1[r]);
            ti1=r;
        }
    }
    ans=min(ans,s1+t1);

    // vector<ll> z2=z;
    // ll s2=INF, si2;
    // rep(i,x.size()){
    //     int l=0, r=z2.size()-1;
    //     while(r-l>1){
    //         int m=(l+r)/2;
    //         if(x[i]>=z2[m]) l=m;
    //         else r=m;
    //     }
    //     if(abs(x[i]-z2[l])<s2){
    //         s2=abs(x[i]-z2[l]);
    //         si2=l;
    //     }
    //     if(abs(x[i]-z2[r])<s2){
    //         s2=abs(x[i]-z2[r]);
    //         si2=r;
    //     }
    // }
    // z2.erase(z2.begin()+si2);

    // ll t2=INF, ti2;
    // rep(i,y.size()){
    //     int l=0, r=z2.size()-1;
    //     while(r-l>1){
    //         int m=(l+r)/2;
    //         if(y[i]>=z2[m]) l=m;
    //         else r=m;
    //     }
    //     if(abs(y[i]-z2[l])<t2){
    //         t2=abs(y[i]-z2[l]);
    //         ti2=l;
    //     }
    //     if(abs(y[i]-z2[r])<t2){
    //         t2=abs(y[i]-z2[r]);
    //         ti2=r;
    //     }
    // }
    // ans=min(ans,s2+t2);

    cout<<ans<<endl;

    return 0;
}