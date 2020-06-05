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

string S;
int N;

int main(){
    cin>>S;
    N=S.size();

    ll ans=0;
    rep(i,1<<N-1){
        ll sum=0;
        ll x=S[0]-'0';
        rep(j,N-1){
            if(i>>j&1){
                sum+=x;
                //cout<<x<<' ';
                x=S[j+1]-'0';
            }else{
                int m=S[j+1]-'0';
                x=x*10+m;
            }
        }
        sum+=x;
        //cout<<x<<endl;
        ans+=sum;
    }

    cout<<ans<<endl;
}