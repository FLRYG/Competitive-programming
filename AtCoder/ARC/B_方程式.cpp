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

inline ll digit(ll n){return log10(n)+1;}
ll digit_sum(ll n){
    ll res=0;
    while(n!=0){
        res+=n%10;
        n/=10;
    }
    return res;
}

int main(){
    cin>>N;

    vector<ll> v;
    repn(fx,200){
        if(digit_sum(N-fx)==fx) v.push_back(N-fx);
    }

    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    repr(e,v) cout<<e<<endl;
}