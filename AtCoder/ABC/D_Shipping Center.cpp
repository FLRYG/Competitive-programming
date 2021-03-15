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

int N,M,Q;
int W[50];
int V[50];
int X[50];

int main(){
    cin>>N>>M>>Q;
    rep(i,N) cin>>W[i]>>V[i];
    rep(i,M) cin>>X[i];

    vector<int> ans(Q,0);
    rep(q,Q){
        int L,R;
        cin>>L>>R;
        L--, R--;
        vector<int> XX;
        rep(i,M){
            if(L<=i && i<=R) continue;
            XX.push_back(X[i]);
        }
        sort(XX.begin(),XX.end());
        // repr(e,XX) cout<<e<<' '; cout<<endl;
        vector<int> chk(N,false);
        rep(i,XX.size()){
            int val=0, idx=-1;
            rep(j,N){
                if(chk[j]) continue;
                if(W[j]<=XX[i] && val<=V[j]){
                    if(val==V[j] && W[j]<=W[idx]) continue;
                    val=V[j];
                    idx=j;
                }
            }
            // cout<<idx<<' '<<val<<endl;
            if(idx==-1) continue;
            chk[idx]=true;
            ans[q]+=val;
        }
        // cout<<ans[q]<<endl;
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}