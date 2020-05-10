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

ll N,K;
ll A[200001];
ll P[200001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>A[i];
    fill(P,P+N+1,-1);

    ll t=0;
    ll pos=1;
    do{
        P[pos]=t;
        pos=A[pos];
        t++;
        if(t==K){
            cout<<pos<<endl;
            return 0;
        }
    }while(P[pos]==-1);

    K-=P[pos];
    K%=(t-P[pos]);
    
    rep(i,K){
        pos=A[pos];
    }

    cout<<pos<<endl;
}