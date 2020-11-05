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

string S;

int main(){
    cin>>S;

    int bw=S[0];
    int ans=0;
    for(int i=1;i<S.size();i++){
        if(i%2==1 && S[i]==bw){
            ans++;
        }
        if(i%2==0 && S[i]!=bw){
            ans++;
        }
    }

    cout<<ans<<endl;
}