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

int H,W;
string S[50];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>S[i];

    vector<vector<int>> cnt(H+2,vector<int>(W+2,0));
    repn(i,H) repn(j,W){
        if(S[i-1][j-1]=='#'){
            for(int k=-1;k<=1;k++)
            for(int l=-1;l<=1;l++) cnt[i+k][j+l]++;
        }
    }

    repn(i,H){
        string ans;
        repn(j,W){
            if(S[i-1][j-1]=='#') ans+='#';
            else ans+='0'+cnt[i][j];
        }
        cout<<ans<<endl;
    }
    
    return 0;
}