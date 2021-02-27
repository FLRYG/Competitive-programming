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
typedef pair<int,int> P;
typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,Ma,Mb;
int a[40];
int b[40];
int c[40];

int main(){
    cin>>N>>Ma>>Mb;
    rep(i,N) cin>>a[i]>>b[i]>>c[i];

    vector<vector<int>> dp(401,vector<int>(401,INF));
    dp[0][0]=0;
    rep(i,N){
        vector<vector<int>> v(401,vector<int>(401,INF));
        dp[0][0]=0;
        repn(j,400){
            repn(k,400){
                if(a[i]<=j && b[i]<=k){
                    v[j][k]=min(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
                }else{
                    v[j][k]=dp[j][k];
                }
            }
        }
        dp=v;
        // repn(i,3){
        //     repn(j,3){
        //         if(dp[i][j]==INF) cout<<"x ";
        //         else cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    

    int ans=INF;
    for(int ma=Ma, mb=Mb; ma<=400 && mb<=400; ma+=Ma, mb+=Mb){
        ans=min(ans,dp[ma][mb]);
    }
    if(ans==INF) ans=-1;

    cout<<ans<<endl;

    return 0;
}

// int N,Ma,Mb;
// int a[40];
// int b[40];
// int c[40];

// int main(){
//     cin>>N>>Ma>>Mb;
//     rep(i,N) cin>>a[i]>>b[i]>>c[i];

//     vector<PP> m1(1<<(N/2));
//     rep(i,1<<(N/2)){
//         int aa=0, bb=0, cc=0;
//         rep(j,N/2) if(i>>j&1) aa+=a[j], bb+=b[j], cc+=c[j];
//         m1[i]={cc,{aa,bb}};
//     }
//     map<P,int> m2;
//     rep(i,1<<((N+1)/2)){
//         int aa=0, bb=0, cc=0;
//         rep(j,(N+1)/2) if(i>>j&1) aa+=a[N/2+j], bb+=b[N/2+j], cc+=c[N/2+j];
//         m2[{aa,bb}]=cc;
//     }

//     int ans=INF;
//     rep(i,1<<(N/2)){
//         // cout<<m1[i].second.first<<' '<<m1[i].second.second<<endl;
//         int k=max((m1[i].second.first+Ma-1)/Ma,(m1[i].second.second+Mb-1)/Mb);
//         // cout<<k<<endl;
//         for(int ma=Ma*k, mb=Mb*k; ma<=200 && mb<=200; ma+=Ma, mb+=Mb){
//             int aa=ma-m1[i].second.first;
//             int bb=mb-m1[i].second.second;
//             if(aa==0 && bb==0){
//                 if(ma==0 && mb==0) continue;
//                 ans=min(ans,m1[i].first);
//                 break;
//             }
//             int m=m2[{aa,bb}];
//             if(m==0) continue;
//             ans=min(ans,m1[i].first+m);
//         }
//     }
//     if(ans==INF) ans=-1;

//     cout<<ans<<endl;
    
//     return 0;
// }