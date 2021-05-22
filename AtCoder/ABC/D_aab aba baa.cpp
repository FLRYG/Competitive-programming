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

const int MAX_N = 61;         // n の最大値
vector<vector<ll>> com;  // 前計算の結果を保存
// 動的計画法で前処理
void init() {
    com.assign(MAX_N, vector<ll>(MAX_N));
    com[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_N; j++) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
        }
    }
}

ll A,B,K;

string f(int a, int b, ll k){
    if(a==0 && b==0) return "";
    if(a==0) return "b"+f(a,b-1,k);
    if(b==0) return "a"+f(a-1,b,k);
    // cout<<a<<' '<<b<<endl;
    ll ca=com[a+b-1][a-1];
    ll cb=com[a+b-1][b-1];
    if(K>ca+k) return "b"+f(a,b-1,ca+k);
    else return "a"+f(a-1,b,k);
}

int main(){
    cin>>A>>B>>K;

    init();

    string ans=f(A,B,0);

    cout<<ans<<endl;
    
    return 0;
}