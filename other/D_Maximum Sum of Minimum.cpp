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

int N;
vector<int> v[10000];
int c[10000];

int main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    rep(i,N) cin>>c[i];

    sort(c,c+N,greater<>());

    int ans=0;
    repn(i,N-1) ans+=c[i];
    cout<<ans<<endl;

    vector<int> ans1(N);
    queue<int> q;
    q.push(0);
    int idx=0;
    while(!q.empty()){
        int p=q.front(); q.pop();
        if(ans1[p]==0){
            ans1[p]=c[idx++];
            rep(i,v[p].size()){
                q.push(v[p][i]);
            }
        }
    }

    rep(i,N) cout<<ans1[i]<<' '; cout<<endl;
}