#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N,K,Q;
int A[100000];

int main(){
    cin>>N>>K>>Q;
    rep(i,Q){
        int id;
        cin>>id;
        A[id-1]++;
    }

    rep(i,N){
        if(K-Q+A[i]>0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}