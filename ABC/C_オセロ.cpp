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

int N,Q;
int l[200000], r[200000];

int main(){
    cin>>N>>Q;
    rep(i,Q) cin>>l[i]>>r[i];

    vector<int> sum(N+1,0);
    rep(i,Q){
        sum[l[i]-1]++;
        sum[r[i]]--;
    }

    int ans=0;
    rep(i,N){
        ans+=sum[i];
        cout<<(ans&1);
        ans%=2;
    }
    cout<<endl;
}