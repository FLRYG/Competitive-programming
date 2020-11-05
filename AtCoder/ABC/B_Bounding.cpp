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

int N,X;
int L[105];

int main(){
    cin>>N>>X;
    repn(i,N) cin>>L[i];

    int ans=0;
    int dis=0;
    for(int i=1;i<=N+1;i++){
        dis+=L[i-1];
        if(dis<=X){
            ans++;
        }else{
            break;
        }
    }

    cout<<ans<<endl;
}