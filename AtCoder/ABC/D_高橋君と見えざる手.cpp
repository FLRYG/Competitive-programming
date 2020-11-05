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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,T;
int A[1000000];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i];

    int cost=0;
    int mini=A[0];
    rep(i,N){
        mini=min(mini,A[i]);
        cost=max(cost,A[i]-mini);
    }

    int ans=0;
    map<int,int> cnt;
    mini=A[0];
    rep(i,N){
        mini=min(mini,A[i]);
        cnt[A[i]]++;
        if(A[i]-mini==cost){
            ans+=cnt[mini];
            cnt[mini+1]+=cnt[mini];
            cnt[mini]=0;
        }
    }

    cout<<ans<<endl;
}