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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

struct Case{
    ll N;
    vector<ll> K; 
    vector<ll> L; 
    vector<ll> R;
    Case(ll N, vector<ll> K, vector<ll> L, vector<ll> R){
        this->N=N;
        this->K=K;
        this->L=L;
        this->R=R;
    }
};

ll T;

int main(){
    cin>>T;
    vector<Case> c(T);
    rep(i,T){
        ll n;
        cin>>n;
        vector<ll> k(n),l(n),r(n); 
        rep(j,n){
            cin>>k[j]>>l[j]>>r[j];
        }
        c[i]={n,k,l,r};
    }

    rep(i,T){
        ll N=c[i].N;
        vector<ll> k=c[i].K, l=c[i].L, r=c[i].R;
        
    }
}