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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int mpow(int x,int n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

int N,M;
int a[1000];
int b[1000];
int key[1000];

int main(){
    cin>>N>>M;
    rep(i,M){
        cin>>a[i]>>b[i];
        rep(j,b[i]){
            int c;
            cin>>c;
            key[i]+=mpow(2,c-1);
        }
    }
    //rep(i,M) cout<<i<<':'<<key[i]<<endl;

    vector<int> p(mpow(2,N),-1);
    vector<int> idx(mpow(2,N),-1);
    rep(i,1<<N){
        int res=INF;
        int k=-1;
        rep(j,M){
            //cout<<(key[j]&i)<<endl;
            if((key[j]&i)==i){
                if(a[j]<res){
                    res=a[j];
                    k=j;
                }
            }
        }
        //cout<<i<<':'<<res<<endl;
        if(res==INF) res=-1;
        p[i]=res;
        idx[i]=k;
    }
    p[0]=0;
    idx[0]=-1;

    int maskey=mpow(2,N)-1;
    int ans=INF;
    rep(i,1<<N){
        if(p[i]!=-1 && p[i^maskey]!=-1){
            if(idx[i]!=idx[i^maskey]) ans=min(ans,p[i]+p[i^maskey]);
            else ans=min(ans,p[maskey]);
        }
    }
    if(ans==INF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}