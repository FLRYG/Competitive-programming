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

ll N,M;

int main(){
    cin>>N>>M;

    ll ans=0;
    if(N==1 || M==1){
        if(N==1 && M==1) ans=1;
        else ans=max(N,M)-2;
    }else{
        ans=(N-2)*(M-2);
    }

    cout<<ans<<endl;
}

/*
int main(){
    cin>>N>>M;

    ll ans=abs((N-2)*(M-2));

    cout<<ans<<endl;
}
*/