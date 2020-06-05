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

int N;
int A[100000], B[100000], C[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A,A+N);
    sort(C,C+N);

    int ans=0;
    rep(i,N){
        int* a=upper_bound(A,A+N,B[i]+1);
        int* c=upper_bound(C,C+N,B[i]-1);

        cout<<(a-A)<<(c-C)<<endl;
    }
    
    cout<<ans<<endl;
}


int N;
int A[100000], B[100000], C[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A,A+N);
    sort(C,C+N);

    int ans=0;
    rep(i,N){
        int a;
        int left=-1, right=N, center;
        while(right-left>1){
            center=(left+right)/2;
            if(A[center]<B[i]) left=center;
            else right=center;
        }
        a=right;

        int c;
        left=-1, right=N;
        while(right-left>1){
            center=(left+right)/2;
            if(C[center]>B[i]) right=center;
            else left=center;
        }
        c=N-right;

        ans+=a*c;
    }
    
    cout<<ans<<endl;
}

/*
int N;
int A[100000], B[100000], C[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);

    int cntB[100000];
    int head=0;
    rep(i,N){
        while(head!=N && B[i]<=A[head]) head++;
        cntB[i]=N-head;
    }
    rep(i,N) cout<<cntB[i]<<' '; cout<<'\n';
    int sum=0;
    rep(i,N){
        cntB[N-1-i]+=sum;
        sum=cntB[N-1-i];
    }
    rep(i,N) cout<<cntB[i]<<' '; cout<<'\n';

    int ans=0;
    head=0;
    rep(i,N){
        while(head!=N && C[i]<=B[head]) head++;
        if(head==N) break;
        //cout<<i<<' '<<cntB[head]<<endl;
        ans+=cntB[head];
    }

    cout<<ans<<endl;
}*/