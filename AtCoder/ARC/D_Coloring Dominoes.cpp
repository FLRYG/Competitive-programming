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
typedef pair<int,int> P;

ll const MOD=1'000'000'007;

int N;
string S1,S2;
vector<int> v[52];
map<char,int> m;

int main(){
    rep(i,26){
        m['a'+i]=i;
    }
    rep(i,26){
        m['A'+i]=i+26;
    }
    cin>>N>>S1>>S2;

    ll ans=1;
    ll prev=0;
    rep(i,N){
        if(S1[i]==S2[i]){
            ans*=3-prev;
            prev=1;
        }else{
            if(prev==0){
                ans*=6;
            }
            if(prev==1){
                ans*=2;
            }
            if(prev==2){
                ans*=3;
            }
            prev=2;
            i++;
        }
        ans%=MOD;
    }

    cout<<ans<<endl;
}