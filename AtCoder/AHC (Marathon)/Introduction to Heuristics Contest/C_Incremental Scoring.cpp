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

ll D;
ll c[26+1];
ll s[365+1][26+1];
ll t[365+1];
ll M;
ll d[100000+1], q[100000+1];

ll last[365+1];
ll v[365+1];

int main(){
    cin>>D;
    repn(i,26) cin>>c[i];
    repn(i,D) repn(j,26) cin>>s[i][j];
    repn(i,D) cin>>t[i];
    cin>>M;
    repn(i,M) cin>>d[i]>>q[i];

    ll res=0;
    repn(d,D){
        ll maxi=s[d][t[d]];
        ll k=t[d];
        //cout<<idx<<':'<<maxi<<endl;
        res+=maxi;
        last[k]=d;
        repn(i,26) res-=c[i]*(d-last[i]);
        v[d]=res;
    }

    repn(i,M){
        
    }
}