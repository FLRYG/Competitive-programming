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
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int X;
int chk[2000];

int main(){
    cin>>X;

    chk[1]=1;
    for(int b=2;b<=1000;b++){
        int n=b;
        for(int p=2;p<=10;p++){
            n*=b;
            if(n>X) break;
            chk[n]++;
        }
    }

    int ans;
    for(int i=X;i>=1;i--){
        if(chk[i]){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}