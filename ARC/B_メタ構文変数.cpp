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

int Na,Nb;
int A[100000], B[100000];
map<int,int> m;

int main(){
    cin>>Na>>Nb;
    rep(i,Na) cin>>A[i];
    rep(i,Nb) cin>>B[i];

    rep(i,Na) m[A[i]]++;
    rep(i,Nb) m[B[i]]++;

    double x=0, y=0;
    repr(e,m){
        if(e.second==1) y++;
        if(e.second==2){x++; y++;}
    }

    double ans=x/y;
    cout<<ans<<endl;
}