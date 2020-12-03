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
string S,T;

int main(){
    cin>>N>>S>>T;

    int cnt=0;
    for(int i=N-1;i>=0;i--){
        if(S[i]=='1') cnt++;
        if(T[i]=='1') cnt--;
    }

    if(!(cnt>0 && cnt&1==0)){
        cout<<-1<<endl;
        return 0;
    }
    
    return 0;
}