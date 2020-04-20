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

const int INF=1001001001;

int N,K;
int x[100002];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>x[i];
    x[0]=-INF;
    x[N+1]=INF;

    int L,R;
    repn(i,N){
        if(0<=x[i]){
            L=i-1;
            R=i;
            break;
        }
    }

    int ans=1001001001;
    if(N-R+1>K){

    }
}