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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int R[3000];

int main(){
    cin>>N;
    rep(i,N) cin>>R[i];

    int ans=1;
    int up=-1;
    rep(i,N-1){
        if(R[i]>R[i+1]){
            if(up!=0) ans++;
            up=0;
        }else if(R[i]<R[i+1]){
            if(up!=1) ans++;
            up=1;
        }
    }
    if(ans<3) ans=0;

    cout<<ans<<endl;
}