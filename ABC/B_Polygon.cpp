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
int L[10];

int maxl=0;
int sum=0;

int main(){
    cin>>N;
    rep(i,N){
        cin>>L[i];
        sum+=L[i];
        if(maxl<L[i]) maxl=L[i];
    }
    sum-=maxl;

    if(maxl<sum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}