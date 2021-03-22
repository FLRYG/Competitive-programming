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

ll N;
ll C[500][500];

int main(){
    cin>>N;
    rep(i,N) rep(j,N) cin>>C[i][j];

    rep(i,N-1){
        rep(j,N-1){
            if(C[i+1][j]-C[i][j]!=C[i+1][j+1]-C[i][j+1]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    int id=0;
    rep(j,N) if(C[0][j]<C[0][id]) id=j;

    vector<ll> A(N), B(N);
    rep(i,N) A[i]=C[i][id];
    rep(j,N) B[j]=C[0][j]-C[0][id];

    cout<<"Yes"<<endl;
    rep(i,N) cout<<A[i]<<' '; cout<<endl;
    rep(i,N) cout<<B[i]<<' '; cout<<endl;

    return 0;
}