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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int L[100];

int main(){
    cin>>N;
    rep(i,N) cin>>L[i];

    int ans=0;
    rep(i,N-2){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                if(L[i]==L[j] || L[j]==L[k] || L[k]==L[i]) continue;
                if(L[i]<L[j]+L[k] && L[j]<L[k]+L[i] && L[k]<L[i]+L[j]) ans++;
            }
        }
    }

    cout<<ans<<endl;
}