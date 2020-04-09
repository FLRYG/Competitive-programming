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
string S;
pair<int,int> t[100000];

int main(){
    cin>>N>>K>>S;
    
    int num=S[0]-'0';
    t[0].second=num;
    int index=0;
    rep(i,N){
        if(num==S[i]-'0') t[index].first++;
        else{
            t[++index].first++;
            num=(num+1)%2;
            t[index].second=num;
        }
    }
    index++;
    //rep(i,index) cout<<t[i].first<<' ';
    //cout<<endl;

    int sum=0;
    if(t[0].second==0){
        rep(i,min(2*K,index)){
            sum+=t[i].first;
        }
    }else{
        rep(i,min(2*K+1,index)){
            sum+=t[i].first;
        }
    }
    //cout<<"0:"<<sum<<endl;

    int ans=sum;
    int n=t[index-1].second==0?index-2*K:index-2*K-1;
    repn(i,n){
        if(t[i].second==0){
            sum-=t[i-1].first;
        }else{
            sum-=t[i-1].first;
            sum+=t[i+2*K-1].first+t[i+2*K].first;
        }
        ans=max(ans,sum);
        //cout<<i<<":"<<sum<<endl;
    }

    cout<<ans<<endl;
}