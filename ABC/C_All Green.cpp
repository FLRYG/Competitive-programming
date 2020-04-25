#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int D,G;
int p[101],c[101];
int dp[1001];

int main(){
    cin>>D>>G;
    rep(i,D) cin>>p[i]>>c[i];

    int ans=1001001001;
    for(int i=0;i<1<<D;i++){
        int g=G;
        int res=0;
        int maximum;
        for(int j=0;j<D;j++){
            if(i>>j&1){
                res+=p[j];
                g-=100*(j+1)*p[j]+c[i];
            }else{
                maximum=j;
            }
            cout<<"g="<<g<<endl;
        }
        
        if(G<=0){
            cout<<"aaa"<<endl;
            ans=min(ans,res);
        }else{
            cout<<"bbb"<<endl;
            if(g/(100.0*(maximum+1))<=p[maximum]){
                cout<<"ccc"<<endl;
                res+=ceil(g/(100.0*(maximum+1)));
                ans=min(ans,res);
            }
        }
        cout<<ans<<"\n\n";
    }

    cout<<ans<<endl;
}