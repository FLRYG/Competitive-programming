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

ll N,K;
ll A[200000];
ll sum[200001];
ll ans[200001];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    rep(j,K){
        rep(i,N){
            sum[max((ll)0,i-A[i])]++;
            sum[min(i+A[i]+1,N)]--;
        }
        repn(i,N-1){
            sum[i]+=sum[i-1];
        }
        rep(i,N){
            A[i]=sum[i];
        }
        fill(sum,sum+N,0);
        bool flag=true;
        rep(i,N){
            flag&=(A[i]==N);
        }
        if(flag) break;
    }

    rep(i,N) cout<<A[i]<<' ';
    cout<<endl;
}