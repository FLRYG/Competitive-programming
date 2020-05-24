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
typedef pair<ll,int> P;

ll N;

int main(){
    cin>>N;

    ll res=0;
    for(int i=1;i<=sqrt(N);i++){
        if(N%i==0){
            res+=i;
            if(i!=1) res+=N/i;
            if(i==N/i) res-=i;
        }
    }

    if(res==N){
        cout<<"Perfect"<<endl;
    }else if(res>N){
        cout<<"Abundant"<<endl;
    }else{
        cout<<"Deficient"<<endl;
    }
}


/* 無駄が多い
ll N;
vector<P> p;

ll pow(ll x,ll n){
    if(n==0) return 1;
    if(n&1) return x*pow(x,n-1);
    return pow(x*x,n/2);
}

ll dfs(int i){
    if(p.size()==i) return 1;
    ll res=0;
    ll next=dfs(i+1);
    rep(j,p[i].second+1){
        res+=pow(p[i].first,j)*next;
    }
    return res;
}

int main(){
    cin>>N;

    ll n=N;
    for(int i=2;i<=100000;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            p.push_back(P(i,cnt));
        }
    }
    if(n!=1) p.push_back(P(n,1));
    
    ll ans=dfs(0)-N;
    if(ans==N){
        cout<<"Perfect"<<endl;
    }else if(ans>N){
        cout<<"Abundant"<<endl;
    }else{
        cout<<"Deficient"<<endl;
    }
}
*/