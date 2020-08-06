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
ll const MOD=1000000007;

ll N;
ll num[1001];
ll cnt[1001];

int main(){
    cin>>N;
    repn(i,N) num[i]=i;

    repn(i,N){
        repn(j,N){
            if(j==1) continue;
            while(num[i]%j==0){
                cnt[j]++;
                num[i]/=j;
            }
        }
    }

    ll ans=1;
    repn(i,N){
        ans*=cnt[i]+1;
        ans%=MOD;
    }

    cout<<ans<<endl;
}