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

int N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    if(A[0]>0){
        cout<<-1<<endl;
        return 0;
    }
    repn(i,N-1){
        if(A[i]>A[i-1]+1){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll ans=0;
    repn(i,N-1){
        if(A[i]==A[i-1]+1){
            ans++;
        }else{
            ans+=A[i];
        }
    }

    cout<<ans<<endl;
}
