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

ll K;
ll A[100000];

int main(){
    cin>>K;
    rep(i,K) cin>>A[i];

    ll inf=2, sup=2;
    for(int i=K-1;i>=0;i--){
        if(sup/A[i]-(inf-1)/A[i]<=0){
            cout<<-1<<endl;
            return 0;
        }
        //cout<<i<<endl;
        inf=((inf-1)/A[i]+1)*A[i];
        sup=sup/A[i]*A[i]+A[i]-1;

    }

    cout<<inf<<' '<<sup<<endl;
}