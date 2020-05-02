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

int N,M,Q;
pair<int,pair<int,pair<int,int>>> dabc[50];
map<int,int> ab[11];
int cc[11];
int x[11];

int main(){
    cin>>N>>M>>Q;
    rep(i,Q) cin>>dabc[i].second.first
                >>dabc[i].second.second.first
                >>dabc[i].second.second.second
                >>dabc[i].first;

    sort(dabc,dabc+Q,greater<int>());

    int ans=0;
    rep(i,Q){
        int a=dabc[i].second.first;
        int b=dabc[i].second.second.first;
        int c=dabc[i].second.second.second;
        if(ab[a][b]==0){
            for(int i=a;i<N;i++){
                x[i]++;
            }
            ans+=dabc[i].first;
            ab[a][b]++;
            ab[b][a]++;
            cc[c]++;
        }
    }

    cout<<ans<<endl;
}