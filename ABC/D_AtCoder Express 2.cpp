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
int L[200000], R[200000];
int p[100000], q[100000];

int cnt[501];

int main(){
    cin>>N>>M>>Q;
    rep(i,M) cin>>L[i]>>R[i];
    rep(i,Q) cin>>p[i]>>q[i];

    rep(i,M){
        repn(j,N) if(j<=L[i] || R[i]<=j) cnt[j]++;
    }

    rep(i,Q){
        cout<<min(cnt[p[i]],cnt[q[i]])<<endl;;
    }
}