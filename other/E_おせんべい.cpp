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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int R,C;
int a[10][10000];

int main(){
    cin>>R>>C;
    rep(i,R) rep(j,C) cin>>a[i][j];

    vector<int> sum(C);
    rep(j,C){
        rep(i,R){
            sum[j]+=a[i][j];
        }
    }

    int ans=0;
    rep(n,1<<R){
        vector<int> tmp(C);
        rep(i,C) tmp[i]=sum[i];

        rep(i,R){
            int s=n>>i&1;
            if(s==0) continue;
            rep(j,C){
                if(a[i][j]==1) tmp[j]--;
                else tmp[j]++;
            }
        }

        int res=0;
        rep(i,C) res+=max(tmp[i],R-tmp[i]);
        ans=max(ans,res);
    }

    cout<<ans<<endl;
}