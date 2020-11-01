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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M;
ll H[200000];
ll W[200000];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>H[i];
    rep(i,M) cin>>W[i];

    sort(H,H+N);

    vector<ll> sum1(N);
    vector<ll> sum2(N);
    rep(i,N){
        if(i&1) sum1[i]=H[i]-H[i-1];
        else{
            if(i==0) continue;
            else sum2[i]=H[i]-H[i-1];
        }
    }
    rep(i,N-1){
        sum1[i+1]+=sum1[i];
        sum2[i+1]+=sum2[i];
    }

    ll ans=LINF;
    rep(i,M){
        int l=-1;
        int r=N;
        while(r-l>1) {
            int mid=l + (r - l) / 2;
            if (H[mid]>=W[i]) r = mid;
            else l = mid;
        }

        ll res=0;
        if(r&1){
            res+=sum1[l];
            res+=sum2[N-1]-sum2[l];
            res+=W[i]-H[l];
        }else{
            res+=sum1[r];
            res+=sum2[N-1]-sum2[r];
            res+=H[r]-W[i];
        }
        ans=min(ans,res);
    }

    cout<<ans<<endl;
}