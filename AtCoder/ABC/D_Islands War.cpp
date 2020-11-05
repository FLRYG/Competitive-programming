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
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,M;
pair<int,int> ba[100000];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>ba[i].second>>ba[i].first;

    sort(ba,ba+M);

    int ans=1;
    int b=ba[0].first;
    repn(i,M-1){
        if(b<=ba[i].second){
            ans++;
            b=ba[i].first;
        }
    }

    cout<<ans<<endl;
}