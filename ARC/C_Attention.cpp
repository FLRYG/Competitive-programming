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

int N;
string S;
int W[300002], E[300002];

int main(){
    cin>>N>>S;

    rep(i,N){
        if(S[i+1]=='W') W[i+1]++;
        else E[i+1]++;
        W[i+2]=W[i+1];
        E[i+2]=E[i+1];
    }

    int ans=1001001001;
    rep(i,N){
        int x=(W[i])+(E[N+1]-E[i+1]);
        ans=min(ans,x);
    }

    cout<<ans<<endl;
}