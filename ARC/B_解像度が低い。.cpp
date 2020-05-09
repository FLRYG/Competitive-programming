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
int A[300000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int ans=0;
    int cnt=1;
    repn(i,N-1){
        if(A[i-1]<A[i]) cnt++;
        else{
            if(cnt>=K) ans+=cnt-K+1;
            cnt=1;
        }
    }
    if(cnt>=K) ans+=cnt-K+1;

    cout<<ans<<endl;
}