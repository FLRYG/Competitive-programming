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

int N,M;
int A[100];
double sum=0;

int main(){
    cin>>N>>M;
    rep(i,N){
        cin>>A[i];
        sum+=A[i];
    }

    int c=0;
    rep(i,N){
        if(A[i]>=sum/(4.0*M)) c++;
    }

    if(c>=M){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}