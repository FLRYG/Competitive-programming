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

int N,M;
int k[10];
int s[10][10];
int p[10];

int sta[10];

int main(){
    cin>>N>>M;
    rep(i,M){
        cin>>k[i];
        rep(j,k[i]){
            cin>>s[i][j];
        }
    }
    rep(i,M){
        cin>>p[i];
    }

    int ans=0;
    for(int i=0;i<1<<N;i++){
        for(int j=0;j<N;j++){
            sta[j]=i>>j&1;
        }

        for(int j=0;j<M;j++){
            int sum=0;
            for(int n=0;n<k[j];n++){
                sum+=sta[s[j][n]-1];
            }
            if(sum%2!=p[j]) goto a;
        }
        ans++;
        a:;
    }

    cout<<ans<<endl;
}