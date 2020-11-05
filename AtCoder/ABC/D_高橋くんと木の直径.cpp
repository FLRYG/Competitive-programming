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

int N;

int main(){
    cin>>N;

    vector<int> dist(N+1,0);
    int s=1;
    repn(i,N){
        if(i==s) continue;
        int d;
        cout<<"? "<<s<<" "<<i<<endl;
        cin>>d;
        dist[i]=d;
    }

    int maxi=0;
    repn(i,N){
        if(dist[i]>maxi){
            maxi=dist[i];
            s=i;
        }
    }
    
    repn(i,N){
        if(i==s){
            dist[i]=0;
            continue;
        }
        int d;
        cout<<"? "<<s<<" "<<i<<endl;
        cin>>d;
        dist[i]=d;
    }

    int ans=0;
    repn(i,N) ans=max(ans,dist[i]);

    cout<<"! "<<ans<<endl;
}