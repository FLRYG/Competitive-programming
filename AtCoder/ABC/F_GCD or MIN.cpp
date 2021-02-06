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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

int N;
set<int> cnt;
set<vector<int>> se;
map<vector<int>,int> memo;

void dfs(vector<int> &v){
    if(memo.size()==1) cnt.insert(v[0]);
    if(se.find(v)==se.end()) return;
    int N=v.size();
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            int g,m;
            g=gcd(v[i],v[j]);
            vector<int> vv;
            
        }
    }
}

int main(){
    cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];

    sort(A.begin(),A.end());

    cout<<dfs(A)<<endl;

    return 0;
}