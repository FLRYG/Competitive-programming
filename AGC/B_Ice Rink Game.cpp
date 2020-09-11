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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll K;
ll A[100000];

int main(){
    cin>>K;
    rep(i,K) cin>>A[i];

    ll L=2-1, R=2;
    rep(i,K){
        R=R+A[K-i-1]-1;
    }
    R++;

    ll l=L, r=R;
    while(r-l<1){
        ll mid=(l+r)/2;
        ll res=mid;
        rep(i,K) res=res-res%A[i];
        if(2<=res) r=mid;
        else l=mid;
    }

    if(r==l+1 || r==R){
        cout<<-1<<endl;
    }

    
    cout<<ans1<<' '<<ans2<<endl;
}