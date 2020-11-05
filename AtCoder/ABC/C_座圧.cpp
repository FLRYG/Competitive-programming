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
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int tmp[100000];
    rep(i,N) tmp[i]=a[i];

    sort(tmp,tmp+N);

    map<int,int> m;
    int val=0;
    int prev=tmp[0];
    rep(i,N){
        if(prev==tmp[i]) m[tmp[i]]=val;
        else m[tmp[i]]=++val;
        prev=tmp[i];
    }

    rep(i,N) cout<<m[a[i]]<<endl;
}