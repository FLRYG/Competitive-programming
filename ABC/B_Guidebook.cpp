#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
pair<pair<string,int>,int> SPN[100];

int main(){
    cin>>N;
    rep(i,N){
        cin>>SPN[i].first.first;
        cin>>SPN[i].first.second;
        SPN[i].first.second*=-1;
        SPN[i].second=i+1;
    }

    sort(SPN,SPN+N);

    rep(i,N){
        cout<<SPN[i].second<<endl;
    }
}