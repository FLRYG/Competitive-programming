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

int N,T;
int A[100000];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i];

    vector<int> val(N+1,0);
    rep(i,N) val[N-1-i]=max(A[N-1-i],val[N-i]);
    rep(i,N) val[i]-=A[i];
    sort(val.begin(),val.end()-1,greater<int>());

    int ans=0;
    rep(i,N){
        if(val[i]!=val[0]) break;
        ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}