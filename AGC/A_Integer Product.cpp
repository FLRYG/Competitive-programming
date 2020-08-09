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
typedef long double ld;
typedef pair<ll,ll> P;
//ll const INF=1001001001;
ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N;
double A[200000];
ll a[200000];
P cnt[200000];
ll grid[11][11];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    rep(i,N) a[i]=(ll)(A[i]*1000000000);

    rep(i,N){
        if(a[i]==0){
            grid[9][9]++;
            continue;
        }
        ll two=0,five=0;
        while(a[i]%2==0 && two<9){
            two++;
            a[i]/=2;
        }
        while(a[i]%5==0 && five<9){
            five++;
            a[i]/=5;
        }
        grid[two][five]++;
        cnt[i]=P(two,five);
        cout<<a[i]<<"\n  "<<two<<" "<<five<<endl;
    }

    rep(i,10){
        rep(j,10){
            cout<<grid[i][j]<<' ';
        }cout<<endl;
    }cout<<endl;

    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            grid[i][j]+=grid[i][j+1];
        }
    }
    rep(i,10){
        rep(j,10){
            cout<<grid[i][j]<<' ';
        }cout<<endl;
    }cout<<endl;
    for(int j=9;j>=0;j--){
        for(int i=9;i>=0;i--){
            grid[i][j]+=grid[i+1][j];
        }
    }

    rep(i,10){
        rep(j,10){
            cout<<grid[i][j]<<' ';
        }cout<<endl;
    }cout<<endl;

    ll ans=0;
    rep(i,N){
        P p=cnt[i];
        ll two=p.first, five=p.second;
        ans+=(grid[9-two][9-five]-grid[9-two+1][9-five+1]+1)/2;
    }
    cout<<ans<<endl;
}