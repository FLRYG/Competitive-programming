#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int h[100];

int f(int begin,int end,int m){
    //cout<<begin<<'~'<<end<<endl;
    if(end-begin<=1) return h[begin]-m;
    int minh=100100;
    for(int i=begin;i<end;i++) if(h[i]<minh) minh=h[i];
    int res=minh-m;
    int l=begin;
    for(int i=begin;i<end;i++){
        if(h[i]==minh){
            res+=f(l,i,minh);
            l=i+1;
        }else if(i==end-1){
            res+=f(l,end,minh);
        }
    }
    return res;
}

int main(){
    cin>>N;
    rep(i,N){
        cin>>h[i];
    }

    int ans=f(0,N,0);

    cout<<ans<<endl;
}