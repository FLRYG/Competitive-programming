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

int main(){
    cin>>N;

    int cnt=0;
    repn(i,N){
        if(N%i==0) cnt++;
    }
    if(cnt==2){
        cout<<"impossible"<<endl;
        return 0;
    }

    int div;
    for(int i=2;i<=N;i++){
        if(N%i==0){
            div=i;
            
        }
    }

    cout<<N/2<<endl;
    repn(i,N/2){
        cout<<2<<' '<<2*i-1<<' '<<2*(N-i+1)-1<<endl;
    }
}