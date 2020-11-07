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

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=0;
    repn(i,N){
        int cnt=0;
        rep(j,26){       
            bool a=false,b=false;
            rep(k,i) a|=S[k]==('a'+j);
            for(int k=i;k<N;k++) b|=S[k]==('a'+j);
            if(a&b) cnt++;
        }
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;
    
    return 0;
}