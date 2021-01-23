#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

int N;
int A[200000];

bool f(vector<int> v){
    bool res=true;
    rep(i,v.size()){
        res&=(v[i]<=1)?true:false;
    }
    return res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<int> cnt(20);
    int ans=0;
    int r=0;
    rep(l,N){
        while(r<N){
            rep(i,20) cnt[i]+=A[r]>>i&1;
            if(!f(cnt)){
                rep(i,20) cnt[i]-=A[r]>>i&1;
                break;
            }
            r++;
        }
        // cout<<l<<' '<<r<<endl;
        ans+=r-l;
        rep(i,20) cnt[i]-=A[l]>>i&1;
    }

    cout<<ans<<endl;

    return 0;
}