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
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int P[200000];
int idx[200001];

int main(){
    cin>>N;
    rep(i,N) cin>>P[i];

    rep(i,N) idx[P[i]]=i;

    int ans=0;
    int cnt=0;
    int prev=-1;
    repn(i,N){
        if(prev<idx[i]) cnt++;
        else{
            ans=max(ans,cnt);
            cnt=1;
        }
        prev=idx[i];
    }
    ans=max(ans,cnt);
    
    ans=N-ans;
    cout<<ans<<endl;
}