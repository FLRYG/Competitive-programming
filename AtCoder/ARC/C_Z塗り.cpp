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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S[100];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    int ans=0;
    rep(i,N){
        for(int j=N-1;j>=0;j--){
            if(S[i][j]=='.'){
                ans++;
                rep(k,j+1) S[i][k]='o';
                if(i<N-1) for(int k=j;k<N;k++) S[i+1][k]='o';
            }
        }
    }

    cout<<ans<<endl;
}