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

int main(){
    cin>>N;

    vector<vector<int>> sum(2,vector<int>(N+1,0));
    vector<int> sum2(N+1,0);
    repn(i,N){
        int c,p;
        cin>>c>>p;
        sum[c-1][i]=p;
        rep(j,2) sum[j][i]+=sum[j][i-1];
    }

    int Q;
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        int A=sum[0][r]-sum[0][l-1];
        int B=sum[1][r]-sum[1][l-1];
        cout<<A<<' '<<B<<endl;
    }
    
    return 0;
}