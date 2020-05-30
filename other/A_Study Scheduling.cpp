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

int H1,M1,H2,M2,K;

int main(){
    cin>>H1>>M1>>H2>>M2>>K;

    int h=H2-H1;
    int m=M2-M1;
    int ans=h*60+m-K;

    cout<<ans<<endl;
}