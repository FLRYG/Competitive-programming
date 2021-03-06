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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;

    if(M==0){
        repn(i,N) cout<<2*i-1<<' '<<2*i<<endl;
        return 0;
    }
    if(M<0 || N<=M+1){
        cout<<-1<<endl;
        return 0;
    }

    vector<P> ans;
    repn(i,N-1){
        if(2*i+1<2*(M+2)) ans.push_back({2*i,2*i+1});
        else ans.push_back({2*i+1,2*i+2});
    }
    ans.push_back({1,2*(M+2)});

    rep(i,N) cout<<ans[i].first<<' '<<ans[i].second<<endl;
    
    return 0;
}