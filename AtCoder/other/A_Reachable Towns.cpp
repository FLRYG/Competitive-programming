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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
pair<P,int> p[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>p[i].first.first>>p[i].first.second;
    rep(i,N) p[i].second=i;

    sort(p,p+N);

    cout<<endl;
    //rep(i,N) cout<<p[i].first.first<<' '<<p[i].first.second<<endl;

    vector<P> ans(N);
    int l=0;
    int r=N-p[0].first.second+1;
    ans[0].first=p[0].second;
    ans[0].second=l+r;
    cout<<p[0].first.first<<' '<<p[0].first.second;
    cout<<"  "<<l<<' '<<r<<' '<<endl;
    repn(i,N-1){
        if(p[i-1].first.second<p[i].first.second){
            l++;
            r--;
        }else{
            int a=l, b=r;
            l=
            r=(N-p[i].first.second+1)-((p[i].first.first-1)-l);
        }
        cout<<p[i].first.first<<' '<<p[i].first.second;
        cout<<"  "<<l<<' '<<r<<' '<<endl;
        ans[i].first=p[i].second;
        ans[i].second=l+r;
    }

    sort(ans.begin(),ans.end());

    rep(i,N) cout<<ans[i].second<<endl;
}