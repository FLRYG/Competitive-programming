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
ll const MOD=1000000007;

int N;
int c[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>c[i];

    bool same=true;
    rep(i,N) same&=c[i%N]==c[(i+1)%N];
    if(same){
        cout<<-1<<endl;
        return 0;
    }

    int i=0;
    int cnt=1;
    int ans=0;
    while(c[i%N]==c[(i+1)%N] || i<N){
        if(c[i%N]==c[(i+1)%N]) cnt++;
        else{
            ans=max(ans,cnt);
            cnt=1;
        }
        i++;
    }
    ans=max(ans,cnt);
    ans=(ans+1)/2;

    cout<<ans<<endl;
}