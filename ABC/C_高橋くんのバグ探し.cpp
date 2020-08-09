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
ll const MOD=1000000007;

int N,K;
int T[5][5];

int main(){
    cin>>N>>K;
    rep(i,N) rep(j,K) cin>>T[i][j];

    string ans="Nothing";
    rep(i,(int)pow(K,N)){
        int num=i;
        int res=0;
        rep(j,N){
            res^=T[j][num%K];
            num/=K;
        }
        if(res==0){
            ans="Found";
            break;
        }
    }

    cout<<ans<<endl;
}