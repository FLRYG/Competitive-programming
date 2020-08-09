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

int N,M;
int a[200001];
int b[200001];
int cnt[200001];

int main(){
    cin>>N>>M;
    repn(i,M) cin>>a[i]>>b[i];

    repn(i,M){
        if(a[i]==1 || a[i]==N) cnt[b[i]]++;
        if(b[i]==1 || b[i]==N) cnt[a[i]]++;
    }

    string ans="IMPOSSIBLE";
    repn(i,N){
        if(cnt[i]==2){
            ans="POSSIBLE";
            break;
        }
    }

    cout<<ans<<endl;
}