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

int n,c;
int a[100];

int main(){
    cin>>n>>c;
    rep(i,n) cin>>a[i];

    int ans=1001001001;
    repn(i,10){
        repn(j,10){
            if(i==j) continue;
            int sum=0;
            rep(k,n){
                if(k%2==0){
                    if(a[k]!=i) sum+=c;
                }else{
                    if(a[k]!=j) sum+=c;
                }
            }
            ans=min(ans,sum);
        }
    }

    cout<<ans<<endl;
}