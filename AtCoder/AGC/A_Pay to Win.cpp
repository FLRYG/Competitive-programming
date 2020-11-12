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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T;

int main(){
    cin>>T;

    vector<ll> ans(T);
    rep(t,T){
        ll N,A,B,C,D;
        cin>>N>>A>>B>>C>>D;

        map<ll,ll> m;
        m[0]=0;
        ll two=1;
        rep(i,62){
            if(two>N){
                m[two]=A*i+D;
                break;
            }
            ll thr=1;
            rep(j,62){
                if(two*thr>N){
                    m[two*thr]=A*i+B*j+D;
                    break;
                }
                ll fiv=1;
                rep(k,62){
                    m[two*thr*fiv]=A*i+B*j+C*k+D;
                    if(two*thr*fiv>N) break;
                    fiv*=5;
                }
                thr*=3;
            }
            two*=2;
        }

        ll res=LINF;
        repr(e,m){
            cout<<e.first<<' '<<e.second<<endl;
            res=min(res,e.second+D*abs(e.first-N));
        }

        ans[t]=res;
    }

    rep(i,T) cout<<ans[i]<<endl;
    
    return 0;
}