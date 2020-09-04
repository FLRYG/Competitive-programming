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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int d[100];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>d[i];

    vector<int> v(105);
    rep(i,N+1) v[i]=i;

    rep(i,M){
        swap(v[0],v[d[i]]);
        rep(i,N+1) cout<<v[i]<<' ';
        cout<<endl;
    }

    repn(i,N){
        cout<<v[i]<<endl;
    }
}