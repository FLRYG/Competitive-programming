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

int N,M,D;
string S[100];

int main(){
    cin>>N>>M>>D;
    rep(i,N) cin>>S[i];

    int ans=0;
    rep(i,N-D+1) rep(j,M-D+1){
        bool flag;
        flag=true;
        rep(k,D) if(S[i+k][j]=='#') flag=false;
        if(flag) ans++;
        flag=true;
        rep(k,D) if(S[i][j+k]=='#') flag=false;
        if(flag) ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}