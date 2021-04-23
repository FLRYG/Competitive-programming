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

int N,Q;
int A[200000];
int B[200000];
int C[200000];
int D[200000];

int main(){
    cin>>N>>Q;
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,N) B[i]--;
    rep(i,Q) cin>>C[i]>>D[i];
    rep(i,Q) C[i]--, D[i]--;

    vector<priority_queue<int>> kg(200000,priority_queue<int>());
    rep(i,N) belong[i]=B[i];
    
    return 0;
}



// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <queue>
// #include <deque>
// #include <map>
// #include <unordered_map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// #define repr(e,x) for(auto& e:x)
// using namespace std;
// typedef long long ll;
// typedef long double ld;

// ll N,Q;
// ll A[200000];
// ll blog[200000];
// map<ll,ll,greater<ll>> B[200001];
// ll C[200000], D[200000];
// map<ll,ll> top;

// int main(){
//     cin>>N>>Q;
//     rep(i,N){
//         ll b;
//         cin>>A[i]>>b;
//         blog[i]=b;
//         B[b][A[i]]++;
//     }
//     rep(i,Q) cin>>C[i]>>D[i];
//     cout<<endl;repr(e,B[1]) cout<<e.first<<' '<<e.second<<endl;

//     ll ans=1001001001;
//     repn(i,200000){
//         if(B[i].size()==0) continue;
//         repr(e,B[i]){
//             if(e.second>0){
//                 top[e.first]++;
//                 ans=min(ans,e.first);
//                 break;
//             }
//         }
//     }
//     rep(i,Q){
//         ll minustop;
//         repr(e,B[blog[C[i]-1]]){
//             if(e.second>0){
//                 minustop=e.first;
//                 break;
//             }
//         }
//         if(A[C[i]-1]==minustop && B[blog[C[i]-1]][A[C[i]-1]]==1) top[]
//         B[blog[C[i]-1]][A[C[i]-1]]--;
//         B[D[i]][A[C[i]-1]]++;
//         repr(e,B[blog[C[i]-1]]){
//             if(e.second>0){
//                 top[e.first]++;
//                 break;
//             }
//         }
//         repr(e,B[D[i]]){
//             if(e.second>0){
//                 ans=min(ans,e.first);
//                 break;
//             }
//         }
//         cout<<ans<<endl;
//     }
// }