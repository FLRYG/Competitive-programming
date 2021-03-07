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

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<int>> pos(N+1,vector<int>(0));
    rep(i,N+1) pos[i].push_back(0);
    repn(i,N){
        int a;
        cin>>a;
        pos[a].push_back(i);
    }
    rep(i,N+1) pos[i].push_back(N+1);

    rep(i,N){
        rep(j,pos[i].size()-1){
            if(pos[i][j+1]-pos[i][j]-1>=M){
                cout<<i<<endl;
                return 0;   
            }
        }
    }

    cout<<N<<endl;

    return 0;
}

// int N,M;
// int A[1500000];

// int main(){
//     cin>>N>>M;
//     rep(i,N) cin>>A[i];

//     vector<int> cnt(1500005,0);
//     rep(i,M) cnt[A[i]]++;
//     // cout<<cnt[0]<<' '<<cnt[1]<<endl;

//     set<int> s;
//     rep(i,1500005) s.insert(i);
//     rep(i,M) s.erase(A[i]);

//     int ans=*s.begin();
//     rep(i,N-M){
//         cnt[A[i]]--;
//         cnt[A[i+M]]++;
//         if(cnt[A[i]]==0) s.insert(A[i]);
//         s.erase(A[i+M]);
//         // cout<<(*s.begin())<<endl;
//         ans=min(ans,*s.begin());
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }