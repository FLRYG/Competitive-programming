#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int K;

int main(){
    cin>>K;

    int ans;
    if(K%2==1){
        ans=K/2*(K/2+1);
    }else{
        ans=K*K/4;
    }

    cout<<ans<<endl;
}