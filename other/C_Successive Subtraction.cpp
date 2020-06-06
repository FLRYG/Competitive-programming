#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
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

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int plus=0, minus=0;// zero=0;
    int ans=0;
    rep(i,N){
        ans+=A[i];
        if(A[i]>0) plus++;
        if(A[i]<0) minus++;
        //if(A[i]==0) zero++;
    }
    if(plus==N || minus==N) ans-=2;
    cout<<ans<<endl;

    int left=0, right=N-1;
    if(A[left]*A[right]>0){
        
    }
    while(right-left>1){
        int l=A[left], r=A[right];
        if(abs(A[left+1])>=abs(A[right-1])){
            A[right]=r-l;
        }else{
            A[left]=l-r;
        }
    }
}