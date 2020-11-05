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

int N;
priority_queue<double,vector<double>,greater<double>> V;

int main(){
    cin>>N;
    rep(i,N){
        double x;
        cin>>x;
        V.push(x);
    }

    for(int i=0;i<N-1;i++){
        double x=V.top();
        V.pop();
        double y=V.top();
        V.pop();
        V.push((x+y)/2);
    }

    double ans=V.top();

    cout<<ans<<endl;
}