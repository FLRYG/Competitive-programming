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
int t[2000];
int l[2000];
int r[2000];

int main(){
    cin>>N;
    rep(i,N) cin>>t[i]>>l[i]>>r[i];

    vector<int> id(N);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[&](int i, int j){ return l[i]<l[j]; });

    int ans=0;
    rep(i,N-1) for(int j=i+1;j<N;j++){
        // if(t[id[i]]==1 && t[id[j]]==1 && max(l[id[i]],l[id[j]])<=min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==1 && t[id[j]]==2 && max(l[id[i]],l[id[j]])<=min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==1 && t[id[j]]==3 && max(l[id[i]],l[id[j]])<min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==1 && t[id[j]]==4 && max(l[id[i]],l[id[j]])<min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==2 && max(l[id[i]],l[id[j]])<min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==3 && t[id[j]]==1 && max(l[id[i]],l[id[j]])<=min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==3 && t[id[j]]==2 && max(l[id[i]],l[id[j]])<=min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==3 && t[id[j]]==3 && max(l[id[i]],l[id[j]])<min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==3 && t[id[j]]==4 && max(l[id[i]],l[id[j]])<min(r[id[i]],r[id[j]])) ans++;
        // if(t[id[i]]==4 && max(l[i],l[id[j]])<min(r[i],r[id[j]])) ans++;
        if(t[id[i]]==1 && t[id[j]]==1 && l[id[j]]<=r[id[i]]) ans++;
        if(t[id[i]]==1 && t[id[j]]==2 && l[id[j]]<=r[id[i]]) ans++;
        if(t[id[i]]==1 && t[id[j]]==3 && l[id[j]]<r[id[i]]) ans++;
        if(t[id[i]]==1 && t[id[j]]==4 && l[id[j]]<r[id[i]]) ans++;
        if(t[id[i]]==2 && l[id[j]]<r[id[i]]) ans++;
        if(t[id[i]]==3 && t[id[j]]==1 && l[id[j]]<=r[id[i]]) ans++;
        if(t[id[i]]==3 && t[id[j]]==2 && l[id[j]]<=r[id[i]]) ans++;
        if(t[id[i]]==3 && t[id[j]]==3 && l[id[j]]<r[id[i]]) ans++;
        if(t[id[i]]==3 && t[id[j]]==4 && l[id[j]]<r[id[i]]) ans++;
        if(t[id[i]]==4 && l[id[j]]<r[id[i]]) ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}