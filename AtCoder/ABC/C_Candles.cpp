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

int N,K;
int x[100002];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>x[i];

    int ans=1001001001;
    repn(i,N-K+1){
        ans=min(ans,min(abs(x[i])+abs(x[i+K-1]-x[i]),abs(x[i+K-1])+abs(x[i+K-1]-x[i])));
    }

    cout<<ans<<endl;
}