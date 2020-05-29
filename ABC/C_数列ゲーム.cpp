#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

const int MIN=-1001001001;

int N;
int a[50];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int ans=MIN;
    rep(i,N-1){
        int maxi=MIN;
        for(int j=i+1;j<N;j++){
            int aoki=0, taka=0;
            for(int k=0;k<=j-i;k++){
                if(k%2==0) aoki+=a[k+i];
                else taka+=a[k+i];
            }
            if(aoki>maxi){
                maxi=aoki;
                ans=max(ans,taka);
            }
        }
    }

    cout<<ans<<endl;
}