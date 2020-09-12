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

int main(){
    cin>>N>>C;
    vector<vector<P>> v(C,vector<P>(0));
    rep(i,N){
        int s,t,c;
        cin>>s>>t>>c;
        v[c-1].push_back(P(s,t));
    }

    vector<int> cnt(100002,0);
    vector<int> x(100002,0);
    rep(i,C){
        fill(x.begin(),x.end(),0);
        //cout<<i<<endl;
        //rep(j,v[i].size()) cout<<v[i][j].first<<' '<<v[i][j].second<<endl;
        rep(j,v[i].size()){
            x[v[i][j].first]++;
            x[v[i][j].second]--;
        }
        //repn(j,100) cout<<j%10<<' ';cout<<endl;
        //repn(j,100) cout<<x[j]<<' ';cout<<endl;
        for(int j=100000;j>=0;j--){
            if(x[j]==-1){
                x[j]++;
                x[j+1]--;
            }
        }
        //repn(j,100) cout<<j%10<<' ';cout<<endl;
        //repn(j,100) cout<<x[j]<<' ';cout<<endl;
        rep(j,100002){
            cnt[j]+=x[j];
        }
    }

    repn(i,100001){
        cnt[i]+=cnt[i-1];
    }

    int ans=0;
    repn(i,100000) ans=max(ans,cnt[i]);

    cout<<ans<<endl;
}

/*
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
        int s=1;
        int t=1;
        int a=v[i].size();
        rep(j,a){
            P p=v[i].top(); v[i].pop(); 
            if(t==p.first){
                t=p.second;
            }else{
                if(s!=t){
                    vv.push_back(P(t,s-1));
                }
                s=p.first;
                t=p.second;
            }
        }
        if(s!=t) vv.push_back(P(t,s-1));
    }

    sort(vv.begin(),vv.end());
    //rep(i,vv.size()) cout<<vv[i].second<<' '<<vv[i].first<<endl;

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
*/