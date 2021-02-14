#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll B,C;

int main(){
    cin>>B>>C;

    ll ans=1;
    if(B>0){
        ans+=min(B,C/2);
        ans*=2;
        if((B>C/2 && !(C&1)) || B<=C/2) ans--;
        C--;
        ans+=C/2*2;
        if(!(C&1)) ans--;
    }else if(B==0){
        ans+=C/2*2;
        if(!(C&1)) ans--;
    }else{
        ans+=C/2*2;
        if(!(C&1)) ans--;
        C--;
        ans+=2*min(B,C/2);
        if((B>C/2 && !(C&1)) || B<=C/2) ans--;
    }

    cout<<ans<<endl;

    return 0;
}