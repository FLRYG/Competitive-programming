#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

P rotate(P p){
    return {-p.second,p.first};
}

int N;
P S[100];
P T[100];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i].first>>S[i].second;
    rep(i,N) cin>>T[i].first>>T[i].second;

    sort(S,S+N);
    repn(i,N-1){
        S[i].first-=S[0].first;
        S[i].second-=S[0].second;
    }
    S[0].first=0;
    S[0].second=0;

    // cout<<endl; rep(i,N) cout<<S[i].first<<' '<<S[i].second<<endl; cout<<endl;

    rep(k,4){
        sort(T,T+N);
        repn(i,N-1){
            T[i].first-=T[0].first;
            T[i].second-=T[0].second;
        }
        T[0].first=0;
        T[0].second=0;
        // // rep(i,N) cout<<T[i].first<<' '<<T[i].second<<endl; cout<<endl;
        rep(i,N) T[i]=rotate(T[i]);
        // // rep(i,N) cout<<T[i].first<<' '<<T[i].second<<endl; cout<<endl;
        sort(T,T+N);
        repn(i,N-1){
            T[i].first-=T[0].first;
            T[i].second-=T[0].second;
        }
        T[0].first=0;
        T[0].second=0;
        // rep(i,N) cout<<T[i].first<<' '<<T[i].second<<endl; cout<<endl;
        bool flag=true;
        rep(i,N){
            flag&=S[i].first==T[i].first;
            flag&=S[i].second==T[i].second;
        }
        if(flag){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    
    return 0;
}