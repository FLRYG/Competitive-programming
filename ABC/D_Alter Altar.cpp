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

int N;
string C;

int main(){
    cin>>N>>C;

    int R=0, W=0;
    rep(i,N){
        if(C[i]=='R') R++;
        else W++;
    }

    int r=0, w=0;
    int ans=R;
    rep(i,N){
        if(C[i]=='R') r++;
        else w++;
        int res=0;
        res+=min(w,R-r);
        res+=abs(R-r-w);
        ans=min(ans,res);
    }

    cout<<ans<<endl;
}