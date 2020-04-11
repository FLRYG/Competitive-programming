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

int n;
int v[100000];

int main(){
    cin>>n;
    rep(i,n) cin>>v[i];

    unordered_map<int,int> meven;
    unordered_map<int,int> modd;
    rep(i,n){
        if(i%2==1) meven[v[i]]++;
        else modd[v[i]]++;
    }

    
}