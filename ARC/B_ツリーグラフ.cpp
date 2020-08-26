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

int N,X;
int h[100];
vector<int> v[100];
int cnt[100];

int dfs1(int pos, int parent){
    cnt[pos]+=h[pos];
    rep(i,v[pos].size()){
        if(v[pos][i]==parent) continue;
        cnt[pos]+=dfs1(v[pos][i],pos);
    }
    return cnt[pos];
}

int dfs2(int pos, int parent){
    int res=0;
    rep(i,v[pos].size()){
        if(v[pos][i]==parent) continue;
        if(cnt[v[pos][i]]>0){
            res+=2+dfs2(v[pos][i],pos);
        }
    }
    return res;
}

int main(){
    cin>>N>>X;
    X--;
    rep(i,N) cin>>h[i];
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    dfs1(X,-1);
    int ans=dfs2(X,-1);

    cout<<ans<<endl;
}