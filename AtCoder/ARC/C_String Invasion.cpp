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

    ll ans=0;
    vector<int> cnt(26,0);
    cnt[S[N-1]-'a']++;
    cnt[S[N-2]-'a']++;
    for(int i=N-3;i>=0;i--){
        cnt[S[i]-'a']++;
        if(S[i]==S[i+1]){
            ans+=N-i-cnt[S[i]-'a'];
            rep(i,26) cnt[i]=0;
            cnt[S[i]-'a']=N-i;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}