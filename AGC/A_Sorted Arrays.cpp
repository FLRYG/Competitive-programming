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
ll const MOD=1000000007;

int N;
int A[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];
    A[0]=A[1];

    int ans=1;
    bool rize=true;
    bool first=true;
    repn(i,N){
        if(A[i-1]==A[i]) continue;
        if(first){
            if(A[i-1]<A[i]) rize=true;
            else rize=false;
            first=false;
        }else{
            if(rize){
                if(A[i-1]>A[i]){
                    ans++;
                    first=true;
                }
            }else{
                if(A[i-1]<A[i]){
                    ans++;
                    first=true;
                }
            }
        }
    }

    cout<<ans<<endl;
}

/*
int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=1;
    int prev=A[0];
    repn(i,N-2){
        if((prev<A[i] && A[i]>A[i+1]) || (prev>A[i] && A[i]<A[i+1])){
            ans++;
            i++;
        }
        if(A[i]!=A[i+1]) prev=A[i];
    }

    cout<<ans<<endl;
}*/