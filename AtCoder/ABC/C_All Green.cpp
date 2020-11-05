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
int p[100],c[100];

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
                g-=(100*(j+1)*p[j]+c[j]);
            }else{
                maximum=j;
            }
        }
        
        if(g<=0){
            ans=min(ans,res);
        }else{
            if(g/(100.0*(maximum+1))<=p[maximum]){
                res+=ceil(g/(100.0*(maximum+1)));
                ans=min(ans,res);
            }
        }
    }

    cout<<ans<<endl;
}