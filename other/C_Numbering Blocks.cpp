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

int a[4];
int X[4][4];

int main(){
    repn(i,3) cin>>a[i];
    int N=0;
    repn(i,3) N+=a[i];

    vector<int> v(N+1);
    repn(i,N) v[i]=i;

    int ans=0;
    do{
        bool flag=true;
        int n=0;
        repn(i,3){
            repn(j,a[i]){
                X[i][j]=v[++n];
            }
        }
        //rep(i,4){rep(j,4)cout<<X[i][j]<<' ';cout<<endl;}cout<<endl;
        repn(i,3){
            repn(j,a[i]){
                rep(k,j){
                    flag&=X[i][j]>X[i][k];
                }
                rep(k,i){
                    flag&=X[i][j]>X[k][j];
                }
            }
        }
        if(flag) ans++;
    }while(next_permutation(v.begin()+1,v.end()));

    cout<<ans<<endl;
}