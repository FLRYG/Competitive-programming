#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int P[50];

int main(){
    cin>>N;
    rep(i,N) cin>>P[i];

    int m=0;
    rep(i,N){
        if(i+1!=P[i]) m++;
    }

    if(m<=2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}