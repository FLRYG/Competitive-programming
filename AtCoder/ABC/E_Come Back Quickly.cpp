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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<P>> G(N,vector<P>(0));
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        G[a-1].push_back(P(c,b-1));
    }

    rep(i,N){
        int ans=-1;
        vector<bool> chk(N,false);
        vector<int> cost(N,0);
        priority_queue<P,vector<P>,greater<P>> q;
        q.push(P(0,i));
        while(!q.empty()){
            P p=q.top(); q.pop();
            // cout<<p.first<<' '<<p.second<<endl;
            if(chk[p.second] && p.second==i){
                ans=p.first;
                break;
            }
            if(chk[p.second]) continue;
            cost[p.second]=p.first;
            chk[p.second]=true;
            repr(e,G[p.second]){
                q.push(P(p.first+e.first,e.second));
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}