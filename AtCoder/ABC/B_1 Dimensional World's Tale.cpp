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

int N,M,X,Y;
int x[101];
int y[101];

int main(){
    cin>>N>>M>>X>>Y;
    rep(i,N) cin>>x[i];
    rep(i,M) cin>>y[i];
    x[N]=X;
    y[M]=Y;

    int xmax=-100100, ymin=100100;
    for(int i=0;i<=N;i++){
        if(x[i]>xmax) xmax=x[i];
    }
    for(int i=0;i<=M;i++){
        if(y[i]<ymin) ymin=y[i];
    }

    if(ymin-xmax>0){
        cout<<"No War"<<endl;
    }else{
        cout<<"War"<<endl;
    }
}