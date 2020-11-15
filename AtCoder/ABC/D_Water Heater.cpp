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

ll N,W;
ll S[200000];
ll T[200000];
ll P[200000];

int main(){
    cin>>N>>W;
    rep(i,N) cin>>S[i]>>T[i]>>P[i];

    vector<ll> sum(200002);
    rep(i,N){
        sum[S[i]]+=P[i];
        sum[T[i]]-=P[i];
    }
    rep(i,200002){
        sum[i+1]+=sum[i];
    }

    rep(i,200002){
        if(sum[i]>W){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}