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

int N,a;
string k;
int b[100001];

bool f(string k, int x){
    int ten=1, val=0;
    int n=k.size();
    rep(i,n){
        val+=(k[n-1-i]-'0')*ten;
        if(val>x) return false;
        ten*=10;
    }
    return true;
}

int g(string k){
    int ten=1, val=0;
    int n=k.size();
    rep(i,n){
        val+=(k[n-1-i]-'0')*ten;
        ten*=10;
    }
    return val;
}

ll mod(string k, int m){
    ll ten=1, res=0;
    int n=k.size();
    rep(i,n){
        res+=(k[n-1-i]-'0')*ten;
        res%=m;
        ten*=10;
        ten%=m;
    }
    return res;
}

int main(){
    cin>>N>>a>>k;
    repn(i,N) cin>>b[i];

    int id=0,T,S;
    int pos=a;
    vector<int> chk(N+1,0);
    rep(i,N+1){
        if(chk[pos]){
            T=id-chk[pos]+1;
            S=id-T;
            break;
        }
        id++;
        chk[pos]=id;
        pos=b[pos];
    }
    // repr(e,chk) cout<<e<<' '; cout<<endl;

    if(f(k,S)){
        // cout<<size<<' '<<T<<endl;
        int ans=a, n=g(k);
        rep(i,n) ans=b[ans];
        cout<<ans<<endl;
        return 0;
    }

    ll m=(mod(k,T)-(S%T)+T)%T;
    // cout<<k<<' '<<size<<' '<<T<<' '<<m<<endl;
    
    int ans=a;
    rep(i,S+m) ans=b[ans];

    cout<<ans<<endl;
    
    return 0;
}