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

ll N;
ll A[100000], B[100000];
ll diff[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];

    ll sumA=0, sumB=0;
    rep(i,N){
        sumA+=A[i];
        sumB+=B[i];
    }
    if(sumA<sumB){
        cout<<-1<<endl;
        return 0;
    }

    rep(i,N){
        diff[i]=A[i]-B[i];
    }
    sort(diff,diff+N);

    ll d=sumA-sumB;
    ll ans=N;
    rep(i,N){
        if(diff[i]<0) continue;
        if(diff[i]<=d){
            d-=diff[i];
            ans--;
        }
    }

    cout<<ans<<endl;
}