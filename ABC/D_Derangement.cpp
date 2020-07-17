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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
int p[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>p[i];

    int ans=0;
    repn(i,N-1){
        if(p[i]==i && p[i+1]==i+1){
            swap(p[i],p[i+1]);
            ans++;
        }
    }
    repn(i,N-1){
        if(p[i]==i || p[i+1]==i+1){
            swap(p[i],p[i+1]);
            ans++;
        }
    }

    cout<<ans<<endl;
}