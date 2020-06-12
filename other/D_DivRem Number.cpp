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

ll N;

int main(){
    cin>>N;

    ll ans=0;
    repn(k,sqrt(N)){
        if(N%k==0){
            ll m=N/k;
            if(k<m-1) ans+=m-1;
        }
    }
    cout<<ans<<endl;
}