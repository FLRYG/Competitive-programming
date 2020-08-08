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
ll const MOD=1000000007;

int N;
int a[100];
int cnt[9];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    rep(i,N){
        if(a[i]<=399) cnt[0]++;
        else if(a[i]<=799) cnt[1]++;
        else if(a[i]<=1199) cnt[2]++;
        else if(a[i]<=1599) cnt[3]++;
        else if(a[i]<=1999) cnt[4]++;
        else if(a[i]<=2399) cnt[5]++;
        else if(a[i]<=2799) cnt[6]++;
        else if(a[i]<=3199) cnt[7]++;
        else cnt[8]++;
    }
    //rep(i,9) cout<<i<<' '<<cnt[i]<<endl;

    int mini=0, maxi=0;
    rep(i,8){
        if(cnt[i]>0) mini++;
    }
    maxi=mini+cnt[8];
    if(mini==0) mini=1;

    cout<<mini<<' '<<maxi<<endl;
}