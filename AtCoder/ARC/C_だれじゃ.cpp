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
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
string S;

int main(){
    cin>>N>>K>>S;

    map<vector<int>,P> m;
    vector<int> v(26,0);
    rep(i,K) v[S[i]-'a']++;
    m[v].first=1;
    rep(i,N-K){
        v[S[i]-'a']--;
        v[S[i+K]-'a']++;
        P &e=m[v];
        if(e.first==0) e.first=i+2;
        else e.second=i+2;
    }

    string ans="NO";
    repr(e,m) if(e.second.second-e.second.first>=K){
        ans="YES";
        break;
    }

    cout<<ans<<endl;
    
    return 0;
}