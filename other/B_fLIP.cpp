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

int N,M,K;

int main(){
    cin>>N>>M>>K;

    string ans="No";
    rep(i,N+1){
        rep(j,M+1){
            int cnt=i*(M-j)+j*(N-i);
            if(cnt==K){
                ans="Yes";
                goto a;
            }
        }
    }a:;

    cout<<ans<<endl;
}