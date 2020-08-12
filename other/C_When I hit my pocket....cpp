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

ll K,A,B;

int main(){
    cin>>K>>A>>B;

    ll ans=0;
    ans=max(ans,1+K);
    if(A+1<B){
        ll res=A+(K-(A-1))/2*(B-A);
        if((K-(A-1))%2==1) res++;
        ans=max(ans,res);
    }

    cout<<ans<<endl;
}