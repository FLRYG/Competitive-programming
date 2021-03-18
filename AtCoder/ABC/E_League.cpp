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
int A[1000][1000];

int f(int s, int k, vector<vector<int>> &G, vector<int> &chk, vector<int> &cnt){
    if(chk[s]==k) return -1;
    chk[s]=k;
    int res=1;
    repr(e,G[s]){
        int x=f(e,k,G,chk,cnt);
        if(x==-1) return -1;
        else res=max(res,1+x);
    }
    cnt[s]=res;
    return res;
}

int main(){
    cin>>N;
    rep(i,N) rep(j,N-1){
        cin>>A[i][j];
        A[i][j]--;
    }

    vector<vector<int>> id(N,vector<int>(N,0));
    int k=0;
    rep(i,N-1) for(int j=i+1;j<N;j++){
        id[i][j]=k;
        id[j][i]=k++;
    }
    vector<vector<int>> G(N*(N-1)/2,vector<int>(0));
    rep(i,N) repn(j,N-2){
        G[id[i][A[i][j]]].push_back(id[i][A[i][j+1]]);
    }

    vector<int> chk(N*(N-1)/2,-1);
    vector<int> cnt(N*(N-1)/2,0);
    rep(i,N*(N-1)/2){
        if(chk[i]) continue;
        int x=f(i,i,G,chk,cnt);
    }
    
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
// #include <unordered_map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// using namespace std;
// typedef long long ll;

// /*
// int N;
// queue<int> A[1000];
// bool energy[1000];

// //O(N^3) TLE
// int main(){
//     cin>>N;
//     rep(i,N){
//         rep(j,N-1){
//             int x;
//             cin>>x;
//             A[i].push(x);
//         }
//     }

//     int ans=0;
//     int sum=N*(N-1)/2;
//     while(sum>0){
//         int psum=sum;
//         fill(energy,energy+N,true);
//         ans++;
//         //cout<<"day"<<ans<<endl;
//         for(int i=0;i<N;i++){
//             if(!A[i].empty()){
//                 int x=A[i].front();
//                 if(A[x-1].front()-1==i && energy[i] && energy[x-1]){
//                     //cout<<' '<<i+1<<"vs"<<x<<endl;
//                     A[i].pop();
//                     A[x-1].pop();
//                     energy[i]=false;
//                     energy[x-1]=false;
//                     sum--;
//                 }
//             }
//         }
//         if(psum==sum) break;
//     }

//     if(!sum){
//         cout<<ans<<endl;
//     }else{
//         cout<<-1<<endl;
//     }
// }*/