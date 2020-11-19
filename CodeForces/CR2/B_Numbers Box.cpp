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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T;
int n,m;
int a[10][10];

int main(){
    cin>>T;
    vector<int> ans(T);

    rep(t,T){
        cin>>n>>m;
        rep(i,n) rep(j,m) cin>>a[i][j];

        int sum=0;
        int cnt=0;
        int mini=1000;
        rep(i,n) rep(j,m){
            sum+=abs(a[i][j]);
            cnt+=a[i][j]<0?1:0;
            mini=min(mini,abs(a[i][j]));
        }
        if(cnt%2==1) sum-=2*mini;

        ans[t]=sum;
    }

    rep(i,T) cout<<ans[i]<<endl;
    
    return 0;
}