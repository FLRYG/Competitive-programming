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
#include <set>
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

string S;

int main(){
    cin>>S;
    int N=S.size();

    vector<int> dp(N+1,0);
    

    return 0;
}

// string S;

// int main(){
//     cin>>S;

//     map<string,int> m;
//     int i=0;
//     int ans=0;
//     repn(j,S.size()){
//         if(m[S.substr(i,j-i)]==0){
//             m[S.substr(i,j-i)]++;
//             i=j;
//             ans++;
//         }else if(j==S.size()) ans++;
//     }
    
//     cout<<ans<<endl;
    
//     return 0;
// }