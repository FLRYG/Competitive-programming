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
int A[200];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    N=min(N,8);
    vector<vector<int>> v(200,vector<int>(0));
    repn(i,(1<<N)-1){
        int sum=0;
        rep(j,N) if(i>>j&1){
            sum+=A[j];
            sum%=200;
        }
        v[sum].push_back(i);
    }

    rep(i,200){
        if(v[i].size()>=2){
            vector<int> B,C;
            rep(j,N) if(v[i][0]>>j&1) B.push_back(j+1);
            rep(j,N) if(v[i][1]>>j&1) C.push_back(j+1);
            cout<<"Yes"<<endl;
            cout<<B.size();
            repr(e,B) cout<<' '<<e; cout<<endl;
            cout<<C.size();
            repr(e,C) cout<<' '<<e; cout<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    
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

// ll N;
// ll A[201];

// int main(){
//     cin>>N;
//     repn(i,N) cin>>A[i]; 
//     repn(i,N) A[i]%=200;

//     vector<vector<ll>> dp(N+1,vector<ll>(200));
//     dp[0][0]=1;
//     repn(i,N){
//         rep(j,200){
//             dp[i][(j+A[i])%200]+=dp[i-1][j];
//             dp[i][j]+=dp[i-1][j];
//         }
//     }

//     bool flag=false;
//     ll x;
//     rep(j,200) if(dp[N][j]>=2){
//         flag=true;
//         x=j;
//     }

//     if(!flag){
//         cout<<"No"<<endl;
//         return 0;
//     }

//     // rep(j,200){
//     //     repn(i,N){
//     //         cout<<dp[i][j]<<' ';
//     //     }
//     //     cout<<endl;
//     // }
//     // cout<<x<<endl;

//     vector<ll> B(0),C(0);
//     ll b,c;
//     int f=1;
//     for(int i=N;i>0;i--){
//         if(f==1 && dp[i-1][x]==0){
//             B.push_back(i);
//             C.push_back(i);
//             x=(x-A[i]+200)%200;
//             // cout<<"BC"<<i<<endl;
//             continue;
//         }
//         if(f==1 && dp[i-1][x]>0 && dp[i-1][(x-A[i]+200)%200]>0){
//             b=(x-A[i]+200)%200;
//             c=x;
//             B.push_back(i);
//             // cout<<"B"<<i<<endl;
//             f=0;
//         }else if(f==0){
//             if(dp[i-1][(b-A[i]+200)%200]!=0){
//                 B.push_back(i);
//                 b=(b-A[i]+200)%200;
//                 // cout<<"B"<<i<<endl;
//             }
//             if(dp[i-1][(c-A[i]+200)%200]!=0){
//                 C.push_back(i);
//                 c=(c-A[i]+200)%200;
//                 // cout<<"C"<<i<<endl;
//             }
//         }
//     }
//     reverse(B.begin(),B.end());
//     reverse(C.begin(),C.end());

//     cout<<"Yes"<<endl;
//     cout<<B.size()<<' ';
//     repr(e,B) cout<<e<<' '; cout<<endl;
//     cout<<C.size()<<' ';
//     repr(e,C) cout<<e<<' '; cout<<endl;
    
//     return 0;
// }