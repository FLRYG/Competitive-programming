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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string S,T;

int main(){
    cin>>S>>T;
    
    vector<vector<int>> idx(26,vector<int>(0));
    rep(i,S.size()) idx[S[i]-'a'].push_back(i+1);
    rep(i,T.size()){
        if(!idx[T[i]-'a'].size()){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll k=1;
    ll u=0;
    rep(i,T.size()){
        char c=T[i]-'a';
        ll l=-1, r=idx[c].size();
        while(r-l>1){
            ll m=(l+r)/2;
            if(idx[c][m]>=k) r=m;
            else l=m;
        }
        if(r==idx[c].size()){
            u++;
            k=idx[c][0]+1;
        }else{
            k=idx[c][r]+1;
        }
    }

    ll ans=u*S.size()+k-1;
    cout<<ans<<endl;
    
    return 0;
}