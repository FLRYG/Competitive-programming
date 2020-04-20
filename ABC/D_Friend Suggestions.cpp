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

int N,M,K;
vector<int> fri[100005];
vector<int> blo[100005];


int main(){
    cin>>N>>M>>K;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        fri[a].push_back(b);
        fri[b].push_back(a);
    }
    rep(i,K){
        int c,d;
        cin>>c>>d;
        blo[c].push_back(d);
        blo[d].push_back(c);
    }

    repn(i,N){
        rep(j,fri[i].size()){
            fri[i][j]
        }
    }
}