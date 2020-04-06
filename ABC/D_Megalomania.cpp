#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
pair<int,int> BA[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>BA[i].second>>BA[i].first;

    sort(BA,BA+N);

    int now=0;
    rep(i,N){
        now+=BA[i].second;
        if(now>BA[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}