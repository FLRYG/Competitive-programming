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

int N,T;
int c[100],t[100];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>c[i]>>t[i];

    int ans=100100;
    rep(i,N){
        if(t[i]<=T) ans=min(ans,c[i]);
    }

    if(ans==100100){
        cout<<"TLE"<<endl;
    }else{
        cout<<ans<<endl;
    }
}