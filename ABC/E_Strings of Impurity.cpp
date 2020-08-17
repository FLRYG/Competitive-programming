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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

string s,t;
ll cnts[26];
ll cntt[26];
vector<ll> pos[26];

int main(){
    cin>>s>>t;

    rep(i,s.size()) cnts[s[i]-'a']++;
    rep(i,t.size()) cntt[t[i]-'a']++;
    rep(i,s.size()) pos[s[i]-'a'].push_back(i+1);

    rep(i,26){
        if(cnts[i]==0 && cntt[i]>0){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll cnt=0;
    ll prv=0;
    ll ans=0;
    rep(i,t.size()){
        int c=t[i]-'a';
        ll idx=ans%s.size();
        auto p=upper_bound(pos[c].begin(),pos[c].end(),idx);
        if(p==pos[c].end()){
            p=pos[c].begin();
        }
        if(*p<=prv) cnt++;
        prv=*p;
        ans=cnt*s.size()+prv;
        //cout<<cnt<<' '<<prv<<' '<<ans<<endl;
    }
    
    
    cout<<ans<<endl;
}