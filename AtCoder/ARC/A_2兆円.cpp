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

ll A,K;

int main(){
    cin>>A>>K;
    
    ll ans=0;
    if(K==0){
        ans=(ll)2e12-A;
    }else{
        while(A<(ll)2e12){
            A+=1+K*A;
            ans++;
        }
    }

    cout<<ans<<endl;
}