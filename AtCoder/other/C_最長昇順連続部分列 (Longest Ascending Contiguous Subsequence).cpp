#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[100];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=0;
    rep(i,N) repn(j,N){
        bool flag=true;
        int bef=-INF;
        int l=0;
        for(int k=i;k<j;k++){
            if(A[k]>=bef){
                l++;
                bef=A[k];
            }else{
                flag=false;
                break;
            }
        }
        if(flag) ans=max(ans,l);
    }

    cout<<ans<<endl;
    
    return 0;
}