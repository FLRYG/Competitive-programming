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
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
int x[100000];
int y[100000];
int c[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>x[i]>>y[i]>>c[i];

    vector<vector<int>> B(2*K,vector<int>(2*K));
    vector<vector<int>> W(2*K,vector<int>(2*K));
    rep(i,N){
        x[i]%=2*K;
        y[i]%=2*K;
        if(c[i]=='B') B[x[i]][y[i]]++;
        else W[x[i]][y[i]]++;
    }

    
    
    return 0;
}