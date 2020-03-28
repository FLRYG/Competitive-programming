#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N,M;
pair<int,int> AB[100001];
int daycount[100001];
priority_queue<int> bqueue;

int main(){
    cin>>N>>M;
    rep(i,N){
        cin>>AB[i].first>>AB[i].second;
        daycount[AB[i].first]++;
    }
    sort(AB,AB+N);

    int index=0;
    int ans=0;
    for(int i=1;i<=M;i++){
        for(int j=index;j<index+daycount[i];j++){
            bqueue.push(AB[j].second);
        }
        index+=daycount[i];
        if(!bqueue.empty()){
            ans+=bqueue.top();
            bqueue.pop();
        }
    }

    cout<<ans<<endl;
}