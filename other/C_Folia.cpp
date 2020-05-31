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
ll A[100001];
ll B[100001];
ll sum[100002];

int main(){
    cin>>N;
    rep(i,N+1) cin>>A[i];
    for(int i=N;i>=0;i--) sum[i]=sum[i+1]+A[i];
    if(N==0){
        if(A[0]!=1){
            cout<<-1<<endl;
            return 0;
        }
    }

    B[0]=1-A[0];
    rep(i,N-1){
        ll b1=2*B[i]-A[i+1];
        ll b2=sum[i+2];
        B[i+1]=min(b1,b2);
    }

    bool check=true;
    rep(i,N+1){
        if(i!=N){
            if(!(B[i]<=A[i+1]+B[i+1] && A[i+1]+B[i+1]<=2*B[i])){
                check=false;
                break;
            }
        }
        if(!(B[i]<=sum[i+1])){
            check=false;
            break;
        }
    }
    if(!check){
        cout<<-1<<endl;
        return 0;
    }

    ll ans=0;
    rep(i,N+1){
        ans+=A[i]+B[i];
    }

    cout<<ans<<endl;
}