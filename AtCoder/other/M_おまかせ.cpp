#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int A[1000], B[1000];
int C[100], D[100];

typedef pair<double,int> DI;

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,M) cin>>C[i]>>D[i];

    double l=0, r=INF;
    while(r-l>1e-7){
        double x=(l+r)/2;
        priority_queue<DI> s;
        rep(i,N) s.push({B[i]-x*A[i],0});
        rep(i,M) s.push({D[i]-x*C[i],1});
        int cnt=0, flag=1;
        double res=0;
        while(cnt<5){
            DI di=s.top(); s.pop();
            if(di.second){
                if(flag){
                    res+=di.first;
                    cnt++;
                    flag=false;
                }
            }else{
                res+=di.first;
                cnt++;
            }
        }
        // cout<<l<<' '<<r<<' '<<res<<endl;
        if(res>=0) l=x;
        else r=x;
    }

    cout<<setprecision(16)<<l<<endl;
    
    return 0;
}