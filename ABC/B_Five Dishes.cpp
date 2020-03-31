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

int menu[5];

int main(){
    rep(i,5) cin>>menu[i];

    int ans=100100;
    rep(i,5){
        int sum=0;
        rep(j,5){
            if(i==j || menu[j]%10==0){
                sum+=menu[j];
            }else{
                sum+=(menu[j]+10)/10*10;
            }
        }
        ans=min(ans,sum);
    }

    cout<<ans<<endl;
}