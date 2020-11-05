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

string A;
ll cnt[26];

int main(){
    cin>>A;

    rep(i,A.size()){
        cnt[A[i]-'a']++;
    }

    ll ans=A.size()*(A.size()-1)/2+1;
    for(int i=0;i<26;i++){
        ans-=cnt[i]*(cnt[i]-1)/2;
    }

    cout<<ans<<endl;
}