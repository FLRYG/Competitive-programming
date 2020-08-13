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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll A[2000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    ll ans=0;
    rep(i,N){
        ll bef=0,aft=0;
        rep(j,N){
            if(A[i]>A[j]){
                if(j<i) bef++;
                if(i<j) aft++;
            }
        }
        cout<<bef<<' '<<aft<<endl;
        ans+=aft+(bef+aft)*(K-1);
    }

    cout<<ans<<endl;
}