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
ll A[100000];
bool zero=false;

int main(){
    cin>>N;
    rep(i,N){
        cin>>A[i];
        if(A[i]==0) zero=true;
    }
    if(zero){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1;
    rep(i,N){
        if(A[i]<=1'000'000'000'000'000'000/ans){
            ans*=A[i];
        }else{
            ans=-1;
            break;
        }
    }

    cout<<ans<<endl;
}