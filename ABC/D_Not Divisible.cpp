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

ll N;
ll A[200000];
map<ll,ll> cnt;
map<ll,ll> m;

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cnt[A[i]]++;

    sort(A,A+N);

    ll ans=0;
    rep(i,N){
        if(cnt[A[i]]==1 && m[A[i]]==0){
            ans++;
            for(int j=1;j*A[i]<=A[N-1];j++){
                m[j*A[i]]++;
            }
        }else if(cnt[A[i]]>1 && m[A[i]]==0){
            for(int j=1;j*A[i]<=A[N-1];j++){
                m[j*A[i]]++;
            }
        }
    }

    cout<<ans<<endl;
}