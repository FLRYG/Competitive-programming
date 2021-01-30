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

int N,M,K;
int A[100];
int B[100];
int C[100];
int D[100];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>A[i]>>B[i];
    cin>>K;
    rep(i,K) cin>>C[i]>>D[i];

    int ans=0;
    rep(i,1<<K){
        vector<int> cnt(N+1,0);
        rep(j,K){
            if(i>>j&1) cnt[C[j]]++;
            else cnt[D[j]]++;
        }
        int res=0;
        rep(j,M){
            if(cnt[A[j]] && cnt[B[j]]) res++;
        }
        ans=max(ans,res);
    }

    cout<<ans<<endl;
    
    return 0;
}