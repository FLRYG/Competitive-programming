#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N,M;
pair<ll,ll> AB[100000];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>AB[i].first>>AB[i].second;

    sort(AB,AB+N);

    ll ans=0;
    ll c=0;
    rep(i,N){
        if(c>=M) break;
        ans+=AB[i].first*min(AB[i].second,M-c);
        c+=min(AB[i].second,M-c);
    }

    cout<<ans<<endl;
}