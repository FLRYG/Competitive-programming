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

int N,K;
int A[800][800];

int main(){
    cin>>N>>K;
    rep(i,N) rep(j,N) cin>>A[i][j];

    int ans=INF;
    rep(i,N-K+1){
        vector<int> v;
        rep(l,N){
            rep(k,K){
                v.push_back(A[i+k][l]);
            }
        }
        rep(j,N-K+1){
            int begin=j*K, end=j*K+K*K;
            int l=0, r=INF;
            while(r-l>1){
                int m=(l+r)/2;
                int cnt=0;
                for(int k=begin;k<end;k++){
                    if(v[k]>m) cnt++;
                }
                if(cnt>(K*K/2)) l=m;
                else r=m;
            }
            // cout<<l<<' '<<r<<endl;
            ans=min(ans,r);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}