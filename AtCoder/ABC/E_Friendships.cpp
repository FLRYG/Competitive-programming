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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;

int main(){
    cin>>N>>K;

    if(K>(N-1)*(N-2)/2){
        cout<<-1<<endl;
        return 0;
    }

    vector<P> ans;
    repn(i,N-1){
        ans.push_back(P(i,N));
    }

    int M=(N-1)*(N-2)/2-K;
    repn(i,N-2){
        if(M==0) break;
        for(int j=i+1;j<=N-1;j++){
            if(M==0) break;
            M--;
            ans.push_back(P(i,j));
        }
    }

    cout<<ans.size()<<endl;
    repr(e,ans) cout<<e.first<<' '<<e.second<<endl;
    
    return 0;
}