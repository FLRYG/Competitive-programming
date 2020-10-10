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

int N,K;
int A[300000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    vector<int> cnt(300002);
    rep(i,N){
        int l,r;
        l=max(A[i]-K,0);
        r=min(A[i]+K+1,300001);
        cnt[l]++;
        cnt[r]--;
    }
    repn(i,300000){
        cnt[i]+=cnt[i-1];
    }
    repn(i,20){
        cout<<i<<' '<<cnt[i]<<endl;
    }

    int ans=0;
    rep(i,300002){
        ans=max(ans,cnt[i]);
    }

    cout<<ans<<endl;
}