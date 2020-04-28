#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int a[3000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int ans=0;
    rep(i,N) ans+=a[i]-1;

    cout<<ans<<endl;
}