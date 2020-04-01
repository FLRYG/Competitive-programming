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

    int ans=0;
    int sum=0;
    rep(i,S.size()){
        if(S[i]=='A' || S[i]=='C' ||
           S[i]=='G' || S[i]=='T'){
               sum++;
        }else{
            ans=max(ans,sum);
            sum=0;
        }
    }
    ans=max(ans,sum);

    cout<<ans<<endl;
}