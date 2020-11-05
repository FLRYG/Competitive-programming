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

int N,K;
int D[50];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>D[i];

    int ans=0;
    repn(k,min(N,K)){
        rep(m,k+1){
            vector<int> v;
            int res=0;
            //cout<<m<<' '<<k-m<<' '<<'/';
            rep(i,m){
                //cout<<D[i]<<' ';
                v.push_back(D[i]);
                res+=D[i];
            }
            //cout<<'/';
            rep(i,k-m){
                //cout<<D[N-i-1]<<' ';
                v.push_back(D[N-i-1]);
                res+=D[N-i-1];
            }
            //cout<<endl;
            sort(v.begin(),v.end());
            //rep(i,v.size()) cout<<v[i]<<' '; //cout<<endl;
            //cout<<res<<endl;
            rep(i,K-k){
                //cout<<v[i]<<endl;
                if(v[i]<0) res+=-v[i];
                else break;
            }
            //cout<<' '<<res<<endl;
            ans=max(ans,res);
        }
    }

    cout<<ans<<endl;
}