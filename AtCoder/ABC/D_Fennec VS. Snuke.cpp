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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>());
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<int> color(N,-1);
    queue<P> q;
    q.push(P(0,1));
    q.push(P(N-1,2));
    while(!q.empty()){
        int p=q.front().first;
        int c=q.front().second;
        q.pop();
        if(color[p]!=-1) continue;
        color[p]=c;
        repr(e,G[p]) q.push(P(e,c));
    }

    int one=0;
    int two=0;
    rep(i,N){
        if(color[i]==1) one++;
        if(color[i]==2) two++;
    }

    string ans;
    if(one>two) ans="Fennec";
    else ans="Snuke";

    cout<<ans<<endl;
    
    return 0;
}