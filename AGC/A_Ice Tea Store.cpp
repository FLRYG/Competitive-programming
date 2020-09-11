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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll Q,H,S,D;
ll N;

int main(){
    cin>>Q>>H>>S>>D>>N;

    Q*=4;
    H*=2;

    S=min(S,min(Q,H));
    ll ans=min(S*N,N/2*D+N%2*S);

    cout<<ans<<endl;
}