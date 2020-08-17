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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,L;
string G[21];
int res[10];

int main(){
    cin>>N>>L;
    cin.ignore();
    rep(i,L+1) getline(cin,G[i]);

    rep(i,N) res[i]=i;

    rep(i,L){
        rep(j,2*N-1){
            if(G[i][j]=='-') swap(res[j/2],res[j/2+1]);
        }
    }

    int ans=0;
    rep(i,N*2-1) if(G[L][i]=='o') ans=res[i/2]+1;

    cout<<ans<<endl;
}