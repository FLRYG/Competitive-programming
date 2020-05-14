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

ll N,P;
ll cnt[100001];

int main(){
    cin>>N>>P;

    for(int i=2;i<=1000000;i++){
        while(P%i==0){
            P/=i;
            cnt[i]++;
        }
    }

    ll ans=1;
    ll maxi=0;
    for(int i=2;i<=1000000;i++){
        cnt[i]>
    }
}