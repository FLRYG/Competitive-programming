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
int t[4];

int main(){
    cin>>N;
    rep(i,N) cin>>t[i];

    int ans=INF;
    rep(i,1<<N){
        int zero=0, one=0;
        rep(j,N){
            int x=i>>j&1;
            if(x) one+=t[j];
            else zero+=t[j];
        }
        ans=min(ans,max(zero,one));
    }

    cout<<ans<<endl;
}