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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int K;
string S,T;

int main(){
    cin>>K>>S>>T;

    vector<ll> cntA(10,0);
    vector<ll> cntB(10,0);
    rep(i,4){
        cntA[S[i]-'0']++;
        cntB[T[i]-'0']++;
    }

    ll A=0, B=0;
    ll ten[]={1,10,100,1000,10000,100000};
    repn(i,9){
        repn(j,9){
            cntA[i]++;
            cntB[j]++;
            if(cntA[i]+cntB[i]>K || cntA[j]+cntB[j]>K){
                cntA[i]--;
                cntB[j]--;
                continue;
            }
            ll a=0, b=0;
            repn(k,9){
                a+=k*ten[cntA[k]];
                b+=k*ten[cntB[k]];
            }
            cntA[i]--;
            cntB[j]--;
            if(a>b){
                if(i==j) A+=(K-cntA[i]-cntB[j])*(K-cntA[i]-cntB[j]-1);
                else A+=(K-cntA[i]-cntB[i])*(K-cntA[j]-cntB[j]);
            }else{
                if(i==j) B+=(K-cntA[i]-cntB[j])*(K-cntA[i]-cntB[j]-1);
                else B+=(K-cntA[i]-cntB[i])*(K-cntA[j]-cntB[j]);
            }
        }
    }
    // cout<<A<<' '<<B<<endl;

    double ans=A+B;
    ans=(double)A/ans;

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}