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

ll N,X;
ll L[51],P[51];

ll f(ll n){
    
}

int main(){
    L[0]=1,P[0]=1;
    cin>>N>>X;

    repn(i,N){
        L[i]=2*L[i-1]+3;
        P[i]=2*P[i-1]+1;
    }

    ll ans=0;
    int i=0;
    while(X>0){
        if(X>L[i]){
            i++;
        }else if(X<L[i]){
            cout<<"ll"<<endl;
            ans+=P[i-1]+2;
            X-=L[i-1];
            i=0;
        }else{
            ans=P[i];
            X=0;
        }
    }

    cout<<ans<<endl;
}