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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int X[100000];
int L[100000];
P rl[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i]>>L[i];

    rep(i,N){
        int l=X[i]-L[i];
        int r=X[i]+L[i];
        rl[i]=P(r,l);
    }

    sort(rl,rl+N);

    int ans=0;
    int pos=-1001001001;
    rep(i,N){
        if(pos<=rl[i].second){
            ans++;
            pos=rl[i].first;
        }
    }

    cout<<ans<<endl;
}