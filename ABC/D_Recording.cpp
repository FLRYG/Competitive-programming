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
typedef pair<pair<int,int>,int> PP;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,C;
bool chk[100000];

int main(){
    cin>>N>>C;
    vector<priority_queue<P,vector<P>,greater<P>>> p(C+1,vector<P>(0));
    rep(i,N){
        int s,t,c;
        cin>>s>>t>>c;
        p[c].push_back(P(s,t));
    }
    repn(i,C){
        int s=0;
        int t=0;
        rep(j,p[i].size()){

        }
    }


    P p[100000];
    rep(i,N){
        p[i].first.first=t;
        p[i].first.second=s;
        p[i].second=c;
    }

    sort(p,p+N);

    int ans=0;
    rep(k,C){
        int time=0;
        int cnt=0;
        int bef=-1;
        rep(i,N){
            //cout<<p[i].first.second<<endl;
            if(!chk[i] && (p[i].first.second>=time 
            || (bef==p[i].second && p[i].first.second>=time-1))){
                time=p[i].first.first;
                cnt++;
                chk[i]=true;
                bef=p[i].second;
            }
            //cout<<time<<endl;
        }
        if(cnt==0) break;
        ans++;
    }

    cout<<ans<<endl;
}