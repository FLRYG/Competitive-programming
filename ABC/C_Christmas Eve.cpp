#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,K;
int h[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>h[i];

    sort(h,h+N);

    int ans=1001001001;
    rep(i,N-K+1){
        ans=min(ans,h[i+K-1]-h[i]);
    }

    cout<<ans<<endl;
}