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

int Q;
int l[100000];
int r[100000];
int prime[100001];
int cnt[100001];

int main(){
    cin>>Q;
    rep(i,Q) cin>>l[i]>>r[i];

    repn(i,100000){
        repn(j,100000/i){
            prime[i*j]++;
        }
    }
    
    repn(i,100000){
        cnt[i]=cnt[i-1];
        if(prime[i]==2 && prime[(i+1)/2]==2) cnt[i]++;
    }

    rep(i,Q){
        int ans=cnt[r[i]]-cnt[l[i]-1];
        cout<<ans<<endl;
    }
}