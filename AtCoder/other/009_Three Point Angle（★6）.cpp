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

int N;
int X[2000];
int Y[2000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];

    double ans=0;
    rep(i,N){
        vector<double> theta(0);
        rep(j,N){
            if(i==j) continue;
            theta.push_back(atan2(Y[j]-Y[i],X[j]-X[i])*180/PI);
        }
        rep(j,N-1) if(theta[j]==-180) theta[j]=180;
        sort(theta.begin(),theta.end());
        rep(j,N-1){
            int l=0, r=N-2;
            double alpha=180+theta[j];
            if(alpha>180) alpha-=360;
            while(r-l>1){
                int m=(l+r)/2;
                if(theta[m]<alpha) l=m;
                else r=m;
            }
            double res=abs(theta[j]-theta[l]);
            if(res>180) res=360-res;
            ans=max(ans,res);
            res=abs(theta[j]-theta[r]);
            if(res>180) res=360-res;
            ans=max(ans,res);
        }
    }

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}