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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,M,Q;
int G[501][501];
int p[100000], q[100000];
int sum[501][501];

int cnt[501];

int main(){
    cin>>N>>M>>Q;
    rep(i,M){
        int l,r;
        cin>>l>>r;
        G[l][r]++;
    }
    rep(i,Q) cin>>p[i]>>q[i];

    repn(i,N){
        repn(j,N){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]+G[i][j]-sum[i-1][j-1];
        }
    }

    rep(i,Q){
        int ans=0;
        int pp=p[i];
        int qq=q[i];
        ans=sum[qq][qq]-sum[pp-1][qq]-sum[qq][pp-1]+sum[pp-1][pp-1];
        cout<<ans<<endl;
    }
}