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

int N;
int A[3][101];

int main(){
    cin>>N;
    repn(i,2) repn(j,N) cin>>A[i][j];

    repn(i,N){
        A[1][i]+=A[1][i-1];
        A[2][i]+=A[2][i-1];
    }

    int ans=0;
    repn(i,N){
        ans=max(ans,A[1][i]+A[2][N]-A[2][i-1]);
    }

    cout<<ans<<endl;

    return 0;
}