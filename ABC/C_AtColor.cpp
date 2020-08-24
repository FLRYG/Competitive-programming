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

int n;
int sum[1000002];

int main(){
    cin>>n;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        sum[a]++;
        sum[b+1]--;
    }

    rep(i,1000001){
        sum[i+1]+=sum[i];
    }

    int ans=0;
    rep(i,1000001){
        ans=max(ans,sum[i]);
    }

    cout<<ans<<endl;
}