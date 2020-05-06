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

int N,C,K;
int T[100000];

int main(){
    cin>>N>>C>>K;
    rep(i,N) cin>>T[i];
    sort(T,T+N);

    bool first=true;
    int s;
    int ans=0;
    int cnt=0;
    rep(i,N){
        if(first){
            cnt++;
            s=T[i]+K;
            first=false;
            continue;
        }
        if(cnt<C && T[i]<=s){
            cnt++;
        }else{
            cnt=0;
            ans++;
            first=true;
            i--;
        }
    }
    if(cnt) ans++;

    cout<<ans<<endl;
}