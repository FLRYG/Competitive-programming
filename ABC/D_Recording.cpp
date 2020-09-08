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
typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,C;
bool chk[100000];

int main(){
    cin>>N>>C;
    vector<priority_queue<P,vector<P>,greater<P>>> v(C+1,priority_queue<P,vector<P>,greater<P>>());
    rep(i,N){
        int s,t,c;
        cin>>s>>t>>c;
        v[c].push(P(s,t));
    }
    vector<P> vv(0);
    repn(i,C){
        int s=0;
        int t=0;
        int a=v[i].size();
        rep(j,a){
            P p=v[i].top(); v[i].pop(); 
            if(t==p.first){
                t=p.second;
            }else{
                if(s!=0 || t!=0){
                    vv.push_back(P(t,s-1));
                }
                s=p.first;
                t=p.second;
            }
        }
        vv.push_back(P(t,s-1));
    }

    sort(vv.begin(),vv.end());

    int ans=0;
    rep(i,C){
        int cnt=0;
        int bef=0;
        rep(j,vv.size()){
            if(!chk[j] && vv[j].second>=bef){
                bef=vv[j].first;
                cnt++;
                chk[j]=true;
            }
        }
        if(cnt==0) break;
        ans++;
    }

    cout<<ans<<endl;
}