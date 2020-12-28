#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[200000];
int B[200000];
int cntA[200001];
int cntB[200001];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cntA[A[i]]++;
    rep(i,N) cntB[B[i]]++;

    repn(i,N){
        if(N-cntA[i]<cntB[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    // vector<int> sumA(N+1,0);
    // repn(i,N) sumA[i]=sumA[i-1]+cntA[i];

    stack<int> stk;
    rep(i,N) stk.push(B[i]);
    vector<int> ans(N,-1);
    rep(i,2*N){
        if(ans[i%N]==-1 && A[i%N]!=stk.top()){
            ans[i%N]=stk.top();
            stk.pop();
        }
    }
    if(!stk.empty()){
        queue<int> que;
        rep(i,N) que.push(B[i]);
        fill(ans.begin(),ans.end(),-1);
        rep(i,2*N){
            if(ans[i%N]==-1 && A[i%N]!=que.front()){
                ans[i%N]=que.front();
                que.pop();
            }
        }
    }

    cout<<"Yes"<<endl;
    rep(i,N) cout<<ans[i]<<' '; cout<<endl;

    return 0;
}

// int main(){
//     cin>>N;
//     rep(i,N) cin>>A[i];
//     rep(i,N) cin>>B[i];
//     rep(i,N) cntA[A[i]]++;
//     rep(i,N) cntB[B[i]]++;

//     repn(i,N){
//         if(N<cntA[i]+cntB[i]){
//             cout<<"No"<<endl;
//             return 0;
//         }
//     }

//     int x=0;
//     int cnt=0;
//     repn(i,N){
//         if(cntA[i]+cntB[i]>cnt){
//             cnt=cntA[i]+cntB[i];
//             x=i;
//         }
//     }

//     int idxa=0;
//     int idxb=0;
//     if(A[N-1]==x) idxa=N-1;
//     if(B[0]==x) idxb=0;
//     rep(i,N-1){
//         if(A[i]==x && A[i+1]!=x){
//             idxa=i;
//         }
//         if(B[i]!=x && B[i+1]==x){
//             idxb=i+1;
//         }
//     }
//     //cout<<idxa<<' '<<idxb<<endl;

//     cout<<"Yes"<<endl;
//     for(int i=N+idxb-idxa-1;i<N+idxb-idxa-1+N;i++){
//         cout<<B[i%N]<<' ';
//     }
//     cout<<endl;
// }