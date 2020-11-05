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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string N;

int main(){
    cin>>N;

    int ans=9*(N.size()-1);
    ans+=N[0]-'0'-1;
    repn(i,N.size()-1){
        if(N[i]!='9'){
            goto a;
        }
    }
    ans++;
    a:;

    cout<<ans<<endl;
}