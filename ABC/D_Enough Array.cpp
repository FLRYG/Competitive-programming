#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N,K;
ll a[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>a[i];

    ll ans=0;
    ll sum=0;
    ll l=0,r=0;
    while(r<N || sum>=K){
        if(sum<K){
            sum+=a[r++];
        }else{
            ans+=N-r+1;
            sum-=a[l++];
        }
        //cout<<l<<' '<<r<<' '<<sum<<endl;
    }

    cout<<ans<<endl;
}