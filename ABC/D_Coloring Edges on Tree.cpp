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

struct E{
    int to,id;
    E(int to,int id):to(to),id(id){}
};

int N;
vector<E> G[100001];
int ans[100001];

void dfs(){

}

int main(){
    cin>>N;
    repn(i,N){
        int a,b;
        cin>>a>>b;
        G[a].push_back(E(b,i));
        G[b].push_back(E(a,i));
    }

    int K=0;
    repn(i,N){
        K=max(K,(int)G[i].size());
    }

    dfs()

    repn(i,N){

    }
}