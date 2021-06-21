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

int main(){
    cin>>N;
    vector<string> S(N), T(N);
    rep(i,N) cin>>S[i];
    rep(i,N) cin>>T[i];

    int ans=INF;
    rep(n,4){
        // rep(i,N) cout<<S[i]<<endl; cout<<endl;
        int cnt=n;
        if(n==3) cnt=1;
        rep(i,N) rep(j,N){
            if(S[i][j]!=T[i][j]) cnt++;
        }
        ans=min(ans,cnt);
        vector<string> tmp(N,string(N,'#'));
        rep(i,N) rep(j,N) tmp[j][N-i-1]=S[i][j];
        S=tmp;
    }

    cout<<ans<<endl;
    
    return 0;
}