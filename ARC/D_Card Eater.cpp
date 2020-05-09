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
int cnt[100001];

int main(){
    cin>>N;
    rep(i,N){
        int a;
        cin>>a;
        cnt[a]++;
    }
    repn(i,100000) cnt[i]=max(0,cnt[i]-1);

    int ans=N;
    int sum=0;
    repn(i,100000){
        sum+=cnt[i];
    }
    ans-=sum;
    if(sum%2==1) ans--;

    cout<<ans<<endl;
}