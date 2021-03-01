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

int N,M;

int main(){
    map<string,int> S,T;
    string u;
    cin>>N;
    rep(i,N){
        cin>>u;
        S[u]++;
    }
    cin>>M;
    rep(i,M){
        cin>>u;
        T[u]++;
    }

    int ans=0;
    repr(e,S){
        int x=0;
        x+=e.second;
        x-=T[e.first];
        ans=max(ans,x);
    }

    cout<<ans<<endl;

    return 0;
}