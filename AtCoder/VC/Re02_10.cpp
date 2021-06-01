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

int A,B,C,D,E,F;

int main(){
    cin>>A>>B>>C>>D>>E>>F;
    
    vector<int> water(F+1);
    vector<int> sugar(F+1);
    water[0]=1;
    sugar[0]=1;
    repn(i,F){
        if(100*A<=i) water[i]|=water[i-100*A];
        if(100*B<=i) water[i]|=water[i-100*B];
    }
    repn(i,F){
        if(C<=i) sugar[i]|=sugar[i-C];
        if(D<=i) sugar[i]|=sugar[i-D];
    }

    // rep(i,F+1) if(water[i]) cout<<i<<' '; cout<<endl;
    // rep(i,F+1) if(sugar[i]) cout<<i<<' '; cout<<endl;

    int w=100*A, s=0;
    repn(i,F) repn(j,F){
        if(water[i] && sugar[j] && i+j<=F && j<=i/100*E){
            // cout<<i<<' '<<j<<endl;
            if((i+j)*100*s<100*j*(w+s)){
                w=i;
                s=j;
            }
        }
    }

    cout<<w+s<<' '<<s<<endl;

    return 0;
}