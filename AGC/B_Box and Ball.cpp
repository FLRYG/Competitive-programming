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

int N,M;
int x[100000], y[100000];
bool red[100001];
int cnt[100001];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>x[i]>>y[i];

    red[1]=true;
    fill(cnt,cnt+N+1,1);
    rep(i,M){
        cnt[x[i]]--;
        cnt[y[i]]++;
        if(red[x[i]]){
            red[y[i]]=true;
            if(cnt[x[i]]<=0) red[x[i]]=false;
        }
    }

    int ans=0;
    repn(i,N){
        if(red[i]) ans++;
    }

    cout<<ans<<endl;
}