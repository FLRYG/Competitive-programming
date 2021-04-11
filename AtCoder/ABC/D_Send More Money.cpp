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

string S[3];

int main(){
    rep(i,3) cin>>S[i];

    vector<int> cnt(26,0);
    rep(i,3) rep(j,S[i].size()) cnt[S[i][j]-'a']=1;
    int sum=0;
    rep(i,26) sum+=cnt[i];
    if(sum>10){
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }

    vector<int> id(26,-1);
    int k=0;
    rep(i,26) if(cnt[i]) id[i]=k++;

    vector<int> num(10,0);
    iota(num.begin(),num.end(),0);
    while(next_permutation(num.begin(),num.end())){
        vector<ll> n(3,0);
        rep(i,3){
            if(num[id[S[i][0]-'a']]==0) goto a;
            rep(j,S[i].size()){
                n[i]*=10;
                n[i]+=num[id[S[i][j]-'a']];
            }
        }
        if(n[0]+n[1]==n[2]){
            rep(i,3) cout<<n[i]<<endl;
            return 0;
        }
        a:;
    }

    cout<<"UNSOLVABLE"<<endl;
    
    return 0;
}