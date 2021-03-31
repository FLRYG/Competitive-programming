#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S,T;

int main(){
    cin>>N>>S>>T;

    int cnt=0;
    rep(i,N){
        if(S[i]=='1') cnt++;
        if(T[i]=='1') cnt--;
    }
    if(cnt<0 || cnt&1){
        cout<<-1<<endl;
        return 0;
    }

    
    
    return 0;
}

// int N;
// string S,T;

// int main(){
//     cin>>N>>S>>T;

//     int cnt=0;
//     rep(i,N){
//         if(S[i]=='1') cnt++;
//         if(T[i]=='1') cnt--;
//     }
//     if(cnt<0 || cnt&1){
//         cout<<-1<<endl;
//         return 0;
//     }

//     int s=0;
//     int ans=0;
//     rep(t,N){
//         if(T[t]=='0') continue;
//         s=t;
//         while(s<N && S[s]=='0') s++;
//         if(s==N){
//             cout<<-1<<endl;
//             return 0;
//         }
//         S[s]='0';
//         ans+=s-t;
//     }
//     // cout<<ans<<endl;
//     // cout<<S<<endl;
//     // cout<<T<<endl;

//     rep(i,N){
//         if(S[i]=='0') continue;
//         int j=i+1;
//         while(j<N && S[j]=='0') j++;
//         ans+=j-i;
//         i=j;
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }