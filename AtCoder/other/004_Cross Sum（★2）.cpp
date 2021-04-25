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

int H,W;
int A[2000][2000];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];

    vector<int> sum1(H,0);
    vector<int> sum2(W,0);
    rep(i,H) rep(j,W){
        sum1[i]+=A[i][j];
        sum2[j]+=A[i][j];
    }

    rep(i,H){
        rep(j,W){
            cout<<sum1[i]+sum2[j]-A[i][j]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}