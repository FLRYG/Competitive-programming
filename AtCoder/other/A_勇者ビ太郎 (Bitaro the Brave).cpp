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

ll H,W;
char S[3001][3001];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>S[i][j];

    vector<vector<ll>> O(H+1,vector<ll>(W+1)); 
    vector<vector<ll>> I(H+1,vector<ll>(W+1));

    repn(i,H) repn(j,W){
        O[i][j]=O[i][j-1];
        if(S[i][j]=='O') O[i][j]++;
        I[i][j]=I[i-1][j];
        if(S[i][j]=='I') I[i][j]++;
    }

    ll ans=0;
    repn(i,H) repn(j,W){
        if(S[i][j]=='J'){
            ans+=(O[i][W]-O[i][j])*(I[H][j]-I[i][j]);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}