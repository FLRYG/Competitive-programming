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
int x[100];
int y[100];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    rep(i,N-2){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                int a=x[j]-x[i];
                int b=y[j]-y[i];
                int c=x[k]-x[i];
                int d=y[k]-y[i];
                if(a*d-b*c==0){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"No"<<endl;
}