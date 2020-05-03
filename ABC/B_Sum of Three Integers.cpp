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
using namespace std;
typedef long long ll;

int K,S;

int main(){
    cin>>K>>S;

    int ans=0;
    for(int i=0;i<=K;i++){
        for(int j=0;j<=K;j++){
            if(0<=S-i-j && S-i-j<=K) ans++;
        }
    }

    cout<<ans<<endl;
}