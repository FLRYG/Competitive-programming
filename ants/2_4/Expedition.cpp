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

int N,L,P;
pair<int,int> AB[1000000];

int main(){
    cin>>N>>L>>P;
    rep(i,N) cin>>AB[i].first>>AB[i].second;
    sort(AB,AB+N);

    priority_queue<int> q;
    int position=0;
    int i=0;
    int ans=-1;
    q.push(P);
    do{
        position+=q.top();
        q.pop();
        ans++;
        while(AB[i].first<=position && i<N){
            q.push(AB[i].second);
            i++;
        }
        if(q.empty()){
            ans=-1;
            break;
        }
    }while(position<L);

    cout<<ans<<endl;
}