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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S;

int main(){
    cin>>N>>S;

    if(N%2==0){
        cout<<-1<<endl;
        return 0;
    }

    string l,r="b";
    repn(i,N/2){
        if(i%3==1){
            l+='a';
            r+='c';
        }else if(i%3==2){
            l+='c';
            r+='a';
        }else{
            l+='b';
            r+='b';
        }
    }

    reverse(l.begin(),l.end());
    string s=l+r;
    int ans=-1;
    if(s==S) ans=N/2;

    cout<<ans<<endl;
}