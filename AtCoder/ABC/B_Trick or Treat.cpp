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

int N,K;
int d[100];
int A[100][100];
int cnt[101];

int main(){
    cin>>N>>K;
    rep(i,K){
        cin>>d[i];
        rep(j,d[i]) cin>>A[i][j];
    }

    rep(i,K){
        rep(j,d[i]){
            cnt[A[i][j]]++;
        }
    }

    int ans=0;
    repn(i,N){
        if(cnt[i]==0) ans++;
    }

    cout<<ans<<endl;
}