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

ll N;

int main(){
    cin>>N;

    ll ans=0;
    repn(i,N){
        if(i%3!=0 && i%5!=0) ans+=i;
    }

    cout<<ans<<endl;
}