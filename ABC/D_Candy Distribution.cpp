#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N,M;
ll A[100001];
ll sum[100001];
ll cnt[100001];

int main(){
    cin>>N>>M;
    repn(i,N){
        cin>>A[i];
    }

    repn(i,N) sum[i]=sum[i-1]+A[i];
    for(int i=0;i<=N;i++) cnt[sum[i]%M]++;

    ll ans=0;
    for(int i=0;i<=M;i++){
        ans+=cnt[i]*(cnt[i]-1);
    }
    ans/=2;

    cout<<ans<<endl;
}