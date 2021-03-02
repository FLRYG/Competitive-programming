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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[2][101];

int main(){
    cin>>N;
    rep(i,2) repn(j,N) cin>>A[i][j];

    rep(i,2) repn(j,N){
        A[i][j]+=A[i][j-1];
    }

    int ans=0;
    repn(i,N){
        ans=max(ans,A[0][i]+A[1][N]-A[1][i-1]);
    }

    cout<<ans<<endl;
    
    return 0;
}