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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int a[200001];
int cnt[100001];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>a[N+i];

    rep(i,N) a[i]=N-i;

    rep(i,N+M){
        if(cnt[a[N+M-i-1]]) continue;
        cnt[a[N+M-i-1]]=true;
        cout<<a[N+M-i-1]<<endl;
    }
}