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

int main(){
    cin>>T;
    rep(i,T){
        ll N,A,B,C,D;
        cin>>N>>A>>B>>C>>D;

        map<ll,ll> dp;
        dp[N]=0;
        dp[0]=LINF;
        queue<ll> q;
        q.push(N);
        while(!q.empty()){
            ll p=q.front(); q.pop();
            if(p%2==0){
                if(dp[p]+A<dp[p/2]){
                    
                }
            }
        }
    }
    
    return 0;
}