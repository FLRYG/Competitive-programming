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

string S;

int main(){
    cin>>S;

    string ans;
    rep(i,12) ans+=S[i];
    if(ans=="WBWBWWBWBWBW") ans="Do";
    else if(ans=="WBWWBWBWBWWB") ans="Re";
    else if(ans=="WWBWBWBWWBWB") ans="Mi";
    else if(ans=="WBWBWBWWBWBW") ans="Fa";
    else if(ans=="WBWBWWBWBWWB") ans="So";
    else if(ans=="WBWWBWBWWBWB") ans="La";
    else if(ans=="WWBWBWWBWBWB") ans="Si";

    cout<<ans<<endl;
}