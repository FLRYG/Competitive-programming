#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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
int a[200000];
int b[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i]>>b[i];

    vector<int> cnt(400001,0);
    rep(i,N){
        cnt[a[i]]++;
        cnt[b[i]]++;
    }

    int ans=0;
    rep(i,N){
        if(cnt[a[i]]==1 || cnt[b[i]]==1){
            ans++;
            cnt[a[i]]--;
            cnt[b[i]]--;
        }else if(a[i]==b[i] && cnt[a[i]]){
            ans++;
            cnt[a[i]]=0;
        }
    }
    repr(e,cnt) if(e) ans++;

    // rep(i,N){
    //     if(a[i]>b[i]) swap(a[i],b[i]);
    // }

    // vector<P> v(N);
    // rep(i,N) v[i]=P(a[i],b[i]);

    // sort(v.begin(),v.end());

    // int ans=0;
    // vector<int> cnt(400001,0);
    // rep(i,N) cnt[v[i].second]++;
    // repr(e,cnt) if(e) ans++;
    // rep(i,N){
    //     if(cnt[v[i].first]==0 && cnt[v[i].second]>1){
    //         ans++;
    //         cnt[v[i].first]++;
    //         cnt[v[i].second]--;
    //     }
    // }

    // rep(i,N){
    //     if(cnt[v[i].first]==0){
    //         ans++;
    //         cnt[v[i].first]++;
    //     }else if(cnt[v[i].second]==0){
    //         ans++;
    //         cnt[v[i].second]++;
    //     }
    // }

    // int ans=0;
    // vector<int> cnt(400001,0);
    // rep(i,N) cnt[a[i]]++;
    // repr(e,cnt) if(e) ans++;

    // rep(i,N){
    //     if(cnt[b[i]]==0 && cnt[a[i]]>1){
    //         ans++;
    //         cnt[b[i]]++;
    //         cnt[a[i]]--;
    //     }
    // }

    cout<<ans<<endl;
    
    return 0;
}