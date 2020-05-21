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
typedef pair<int,int> P;

ll N;

int main(){
    cin>>N;

    ll ans=1001001001;
    repn(i,100000){
        if(N%i==0){
            ll a=i;
            ll b=N/i;
            ll res=max(log10(a),log10(b));
            res++;
            if(res<ans) ans=res;
        }
    }

    cout<<ans<<endl;
}