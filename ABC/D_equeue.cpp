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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,K;
int D[50];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];

    int ans=0;
    repn(k,K){
        rep(m,k+1){
            deque<int> d;
            rep(i,N) d.push_back(D[i]);
            vector<int> v;
            rep(i,m){
                if(!d.empty()) v.push_back(d.front()), d.pop_front();
            }
            rep(j,k-m){
                if(!d.empty()) v.push_back(d.back()), d.pop_back();
            }
            sort(v.begin(),v.end(),greater<>());
            rep(i,min(K-k,(int)v.size())){
                if(v[v.size()-i-1]<0) v.pop_back();
                else break;
            }
            int res=0;
            rep(i,v.size()) res+=v[i];
            cout<<m<<' '<<k-m<<' '<<res<<endl;
            ans=max(ans,res);
        }
    }

    cout<<ans<<endl;
}