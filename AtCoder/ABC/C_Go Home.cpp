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

ll X;

int main(){
    cin>>X;

    ll val=0,ans;
    repn(i,100000){
        val+=i;
        if(X<=val){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
}