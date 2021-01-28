#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

int N;

int main(){
    cin>>N;

    int ans=0;
    repn(i,N){
        int n=i;
        while(n>0){
            if(n%10==7) goto a;
            n/=10;
        }
        n=i;
        while(n>0){
            if(n%8==7) goto a;
            n/=8;
        }
        ans++;
        a:;
    }

    cout<<ans<<endl;
    
    return 0;
}