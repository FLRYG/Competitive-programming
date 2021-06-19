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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
int P[8][10000];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>P[i][j];

    int ans=0;
    rep(n,1<<H){
        int h=0;
        vector<int> cnt(H*W+1,0);
        rep(m,H) if(n>>m&1) h++;
        rep(j,W){
            bool flag=true, first=true;
            int val;
            rep(i,H){
                if(n>>i&1){
                    if(first){
                        first=false;
                        val=P[i][j];
                    }else{
                        flag&=val==P[i][j];
                    }
                }
            }
            if(flag && !first){
                cnt[val]++;
            }
        }
        repr(e,cnt) ans=max(ans,h*e);
    }

    cout<<ans<<endl;
    
    return 0;
}