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
int A[200000];

int main(){
    int m1=0,m2=0;
    cin>>N;
    rep(i,N){
        cin>>A[i];
        if(A[i]>m1){
            m2=m1;
            m1=A[i];
        }else if(A[i]>m2){
            m2=A[i];
        }
    }

    rep(i,N){
        if(A[i]==m1){
            cout<<m2<<endl;
        }else{
            cout<<m1<<endl;
        }
    }
}