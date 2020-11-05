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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,M;

int main(){
    cin>>N>>M;

    int div=1;
    int ans=1;
    while(div*div<=M){
        if(M%div==0){
            if(div>=N) ans=max(ans,M/div);
            if(M/div>=N) ans=max(ans,div);
        }
        div++;
    }

    cout<<ans<<endl;
}