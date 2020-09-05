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
typedef pair<pair<int,int>,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,C;
P p[100000];
bool chk[100000];

int main(){
    cin>>N>>C;
    rep(i,N){
        int s,t,c;
        cin>>s>>t>>c;
        p[i].first.first=t;
        p[i].first.second=s-1;
        p[i].second=c;
    }
    rep(i,N){
        cout<<p[i].first.first<<' '<<p[i].first.second<<' '<<p[i].second<<endl;
    }

    sort(p,p+N);

    int ans=0;
    rep(k,C){
        int time=0;
        int cnt=0;
        rep(i,N){
            cout<<p[i].first.second<<endl;
            if(!chk[i] && p[i].first.second>=time){
                time=p[i].first.first;
                cnt++;
                chk[i]=true;
            }
            cout<<time<<endl;
        }
        if(cnt==0) break;
        ans++;
    }

    cout<<ans<<endl;
}