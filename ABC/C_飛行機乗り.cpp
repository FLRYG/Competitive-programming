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

int N,M,X,Y;

int main(){
    cin>>N>>M>>X>>Y;
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];

    int ans=0;
    int time=0;
    int a=0, b=0;
    while(true){
        while(a<N && A[a]<time) a++;
        if(a==N) break;
        time=A[a]+X;
        while(b<M && B[b]<time) b++;
        if(b==M) break;
        time=B[b]+Y;
        ans++;
    }
    cout<<ans<<endl;
}

/* TLE
int main(){
    cin>>N>>M>>X>>Y;
    vector<ll> a(N),b(M);
    rep(i,N) cin>>a[i];
    rep(i,M) cin>>b[i];

    ll ans=0;
    ll time=0;
    bool A=true;
    while(true){
        vector<ll> v;
        if(A) v=a;
        else v=b;
        int l=-1,r=v.size();
        while(r-l>1){
            int mid=(r+l)/2;
            if(v[mid]<time){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(r!=v.size()){
            if(A){
                time=v[r]+X;
                A=false;
            }else{
                time=v[r]+Y;
                A=true;
            }
            ans++;
        }else{
            break;
        }
    }
    ans/=2;

    cout<<ans<<endl;
}
*/