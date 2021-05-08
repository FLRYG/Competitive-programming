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
int A[3000][5];

int main(){
    cin>>N;
    rep(i,N) rep(j,5) cin>>A[i][j];

    int ok=0, ng=INF;
    while(ng-ok>1){
        int m=(ok+ng)/2;
        vector<int> bit(1<<5,0);
        rep(i,N){
            int x=0;
            rep(j,5){
                if(A[i][j]>=m) x|=1<<j;
            }
            bit[x]=1;
        }
        bool flag=false;
        rep(i,32) rep(j,32) rep(k,32){
            if(bit[i] && bit[j] && bit[k] && (i|j|k)==31){
                flag=true;
                break;
            }
        }
        if(flag) ok=m;
        else ng=m;
    }

    cout<<ok<<endl;
    
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

// int N;

// int main(){
//     cin>>N;
//     vector<vector<int>> A(5,vector<int>(N));
//     rep(j,N) rep(i,5) cin>>A[i][j];

//     // vector<int> id{0,1,2};
//     // int ans=INF;
//     // rep(i,5) ans=min(ans,max(A[i][0],max(A[i][1],A[i][2])));

//     // rep(i,N){
//     //     vector<int> tmp;
//     //     int tmpp=0;
//     //     rep(j,3){
//     //         vector<int> idd=id;
//     //         idd[j]=i;
//     //         int res=INF;
//     //         rep(k,5){
//     //             int m=0;
//     //             rep(l,3) m=max(m,A[k][idd[l]]);
//     //             res=min(res,m);  
//     //         }
//     //         if(res>tmpp){
//     //             tmp=idd;
//     //             tmpp=res;
//     //         }
//     //         repr(e,idd) cout<<e<<' ';
//     //         cout<<res<<endl;
//     //     }
//     //     if(tmpp>ans){
//     //         id=tmp;
//     //         ans=tmpp;
//     //     }
//     // }

//     // cout<<ans<<endl;

//     vector<vector<int>> v(5,vector<int>(N*(N-1)/2,0));
//     int id=0;
//     int ans=0;
//     rep(i,N-1){
//         for(int j=i+1;j<N;j++){
//             rep(k,5) v[k][id]=max(A[k][i],A[k][j]);
//             int res=INF;
//             rep(k,5) res=min(res,v[k][id]);
//             ans=max(ans,res);
//             id++;
//         }
//     }

//     rep(i,5) sort(A[i].begin(),A[i].end(),greater<int>());

//     rep(i,id){
//         rep(j,5){
//             int k=0;
//             int maxi=0;
//             while(A[j][k]>v[j][i]){
//                 int mini=INF;
//                 r
//             }
//         }
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }