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
typedef pair<int,P> IP;
typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
IP A[200];

void solve01(vector<PP> &ans){
    sort(A,A+N);
    vector<PP> B(N);
    rep(i,N){
        int a=0, b=0, c=10000, d=10000;
        a=
    }
}

int main(){
    cin>>N;
    rep(i,N) cin>>A[i].second.first>>A[i].second.second>>A[i].first;

    vector<PP> ans(N);
    solve01(ans);
    repr(e,ans){
        cout<<e.first.first<<' '<<e.first.second<<' '<<e.second.first<<' '<<e.second.second<<endl;
    }
    
    return 0;
}