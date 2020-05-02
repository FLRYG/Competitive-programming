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
using namespace std;
typedef long long ll;

int N,K;
int A[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int p1;
    rep(i,N){
        if(A[i]==1){
            p1=i;
            break;
        }
    }

    int ans=ceil((double)p1/(K-1))+
}