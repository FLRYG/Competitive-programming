#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll X,Y,Z,K;
vector<ll> A,B,C;

int main(){
    cin>>X>>Y>>Z>>K;
    rep(i,X){ll a;cin>>a;A.push_back(a);}
    rep(i,Y){ll a;cin>>a;B.push_back(a);}
    rep(i,Z){ll a;cin>>a;C.push_back(a);}

    sort(A.begin(),A.end(),greater<ll>());
    sort(B.begin(),B.end(),greater<ll>());
    sort(C.begin(),C.end(),greater<ll>());

    priority_queue<ll> ans;
    rep(i,X){
        ll a=A[i];
        rep(j,Y){
            ll b=B[j];
            rep(k,Z){
                ll c=C[k];
                if((i+1)*(j+1)*(k+1)<=K) ans.push(a+b+c);
                else break;
            }
        }
    }

    rep(i,K){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}