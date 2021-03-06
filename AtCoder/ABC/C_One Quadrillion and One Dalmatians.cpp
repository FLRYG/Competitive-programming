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

ll N;

int main(){
    cin>>N;

    string ans;
    while(N!=0){
        char x='a'+((--N)%26);
        ans+=x;
        N/=26;
    }
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;
}
