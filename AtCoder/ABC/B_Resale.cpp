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
int V[20];
int C[20];
int diff[20];

int main(){
    cin>>N;
    rep(i,N) cin>>V[i];
    rep(i,N) cin>>C[i];
    rep(i,N) diff[i]=-(V[i]-C[i]);

    sort(diff,diff+N);

    int ans=0;
    rep(i,N){
        if(diff[i]<0){
            ans+=diff[i];
        }else{
            break;
        }
    }
    ans*=-1;

    cout<<ans<<endl;
}