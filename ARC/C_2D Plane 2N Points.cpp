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
typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
P s[100];
P t[100];
bool ss[100];
bool tt[100];

int main(){
    cin>>N;
    rep(i,N) cin>>s[i].second>>s[i].first;
    rep(i,N) cin>>t[i].first>>t[i].second;

    sort(s,s+N);
    sort(t,t+N);

    int ans=0;
    rep(i,N){
        int c=t[i].first;
        int d=t[i].second;
        rep(j,N){
            int a=s[N-j-1].second;
            int b=s[N-j-1].first;
            if(a<c && b<d && !tt[i] && !ss[N-j-1]){
                ans++;
                tt[i]=true;
                ss[N-j-1]=true;
                //cout<<"("<<a<<","<<b<<") ("<<c<<","<<d<<")"<<endl;
                break;
            }
        }
    }

    cout<<ans<<endl;
}