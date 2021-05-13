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

ll N,W;
ll w[100];
ll v[100];

int main(){
    cin>>N>>W;
    rep(i,N) cin>>w[i]>>v[i];

    vector<vector<ll>> val(4,vector<ll>(1,0));
    rep(i,N) val[w[i]-w[0]].push_back(v[i]);
    rep(i,4) sort(val[i].begin()+1,val[i].end(),greater<ll>());
    rep(i,4) rep(j,val[i].size()-1) val[i][j+1]+=val[i][j];

    ll ans=0;
    rep(i,val[0].size()) rep(j,val[1].size()) rep(k,val[2].size()) rep(l,val[3].size()){
        ll wgt=w[0]*(i+j+k+l)+j+2*k+3*l;
        if(wgt<=W){
            ans=max(ans,val[0][i]+val[1][j]+val[2][k]+val[3][l]);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}



// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <list>
// #include <iomanip>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <bitset>
// #include <chrono>
// #include <random>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// #define repr(e,x) for(auto& e:x)
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// // typedef pair<int,int> P;
// // typedef pair<int,P> IP;
// // typedef pair<P,P> PP;
// double const PI=3.141592653589793;
// int const INF=1001001001;
// ll const LINF=1001001001001001001;
// ll const MOD=1000000007;

// int N,W;
// int w[101];
// int v[101];

// int main(){
//     cin>>N>>W;
//     repn(i,N) cin>>w[i]>>v[i];

//     map<int,int> w2id;
//     w2id[0]=0;
//     repn(i,N) rep(j,4*i) w2id[i*w[1]+j];
//     int i=0;
//     repr(e,w2id) e.second=i++; 

//     vector<int> id2w(0);
//     repr(e,w2id) id2w.push_back(e.first);

//     // repr(e,id2w) cout<<e<<endl;

//     vector<vector<int>> dp(N+1,vector<int>(id2w.size(),0));
//     repn(i,N){
//         repn(j,id2w.size()){
//             dp[i][j]=dp[i-1][j];
//             if(id2w[j]-w[i]>=0){
//                 rep(k,w2id[id2w[j]-w[i]]+1){
//                     dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i]);
//                 }
//             }
//         }
//     }

//     int ans=0;
//     rep(i,w2id[W]+1) ans=max(ans,dp[N][i]);

//     cout<<ans<<endl;
    
//     return 0;
// }