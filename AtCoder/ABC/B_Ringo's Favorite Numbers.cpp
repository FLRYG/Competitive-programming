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

int D,N;

int main(){
    cin>>D>>N;

    int ans;
    int cnt=0;
    if(D==0) repn(i,2000000){
        if(i%100!=0) cnt++;
        if(cnt==N){
            ans=i;
            break;
        }
    }
    if(D==1) repn(i,2000000){
        if(i%100==0 && i%10000!=0 && i%1000000!=0) cnt++;
        if(cnt==N){
            ans=i;
            break;
        }
    }
    if(D==2) repn(i,2000000){
        if(i%10000==0 && i%1000000!=0) cnt++;
        if(cnt==N){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
}