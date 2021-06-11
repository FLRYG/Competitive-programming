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

ll H,W,K,V;
ll A[125][125];

int main(){
    cin>>H>>W>>K>>V;
    vector<vector<ll>> A(H+1,vector<ll>(W+1,0));
    repn(i,H) repn(j,W) cin>>A[i][j];
    repn(i,H) repn(j,W) A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];

    vector<ll> S(1,0);
    S.reserve(H*W+1);
    repn(i,H) repn(j,W) S.push_back(i*j);
    sort(S.begin(),S.end());
    S.erase(unique(S.begin(),S.end()),S.end());

    ll l=0, r=S.size();
    while(r-l>1){
        ll m=(l+r)/2;
        bool flag=false;
        repn(l,sqrt(S[m])){
            ll h=l, w=S[m]/l;
            if(S[m]%l!=0 || h>H || w>W) continue;
            ll cost=S[m]*K;
            repn(i,H-h+1) repn(j,W-w+1){
                ll a=A[i+h-1][j+w-1]-A[i-1][j+w-1]-A[i+h-1][j-1]+A[i-1][j-1];
                if(cost+a<=V){
                    flag=true;
                    goto go;
                }
            }
            swap(h,w);
            if(h>H || w>W) continue;
            repn(i,H-h+1) repn(j,W-w+1){
                ll a=A[i+h-1][j+w-1]-A[i-1][j+w-1]-A[i+h-1][j-1]+A[i-1][j-1];
                if(cost+a<=V){
                    flag=true;
                    goto go;
                }
            }
            go:
            if(flag) break;
        }
        if(flag) l=m;
        else r=m;
    }

    cout<<S[l]<<endl;
    
    return 0;
}