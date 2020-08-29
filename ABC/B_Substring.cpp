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

string S,T;

int main(){
    cin>>S>>T;

    int ans=0;
    rep(i,S.size()-T.size()+1){
        int cnt=0;
        rep(j,T.size()){
            if(S[i+j]==T[j]) cnt++;
        }
        ans=max(ans,cnt);
    }
    ans=T.size()-ans;

    cout<<ans<<endl;
}