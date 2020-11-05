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

ll N,K;
ll cnt[100001];

int main(){
    cin>>N>>K;
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        cnt[a]+=b;
    }

    ll ans;
    ll sum=0;
    repn(i,100000){
        sum+=cnt[i];
        if(K<=sum){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
}