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

int INF=1001001001;
int N;
int w[50];

int main(){
    cin>>N;
    rep(i,N) cin>>w[i];

    int ans=0;
    rep(i,N){
        int x=INF-1;
        rep(j,N){
            if(w[j]<=x){
                x=w[j];
                w[j]=INF;
            }
        }
        if(x!=INF-1){
            ans++;
        }else{
            break;
        }
    }

    cout<<ans<<endl;
}