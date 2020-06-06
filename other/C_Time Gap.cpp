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
int D[51];
int T[24];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];
    D[N]=0;
    sort(D,D+N+1);

    rep(i,N+1){
        if(i&1){
            T[(24-D[i])%24]++;
        }else{
            T[D[i]]++;
        }
    }

    int ans=1001001;
    int sum=1001001;
    rep(i,25){
        if(T[i%24]==1){
            ans=min(ans,sum);
            sum=1;
        }else if(T[i%24]==0){
            sum++;
        }else{
            ans=0;
            break;
        }
    }

    cout<<ans<<endl;
}