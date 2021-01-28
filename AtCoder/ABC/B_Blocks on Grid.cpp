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

int H,W;
int A[100][100];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];

    int mini=INF;
    rep(i,H) rep(j,W){
        mini=min(mini,A[i][j]);
    }

    int ans=0;
    rep(i,H) rep(j,W){
        ans+=A[i][j]-mini;
    }

    cout<<ans<<endl;
    
    return 0;
}