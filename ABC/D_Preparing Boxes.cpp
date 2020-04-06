#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int a[200001];

int M=0;
int ans[200001];

int main(){
    cin>>N;
    repn(i,N){
        cin>>a[i];
        if(i>N/2){
            ans[i]=a[i];
            if(a[i]==1) M++;
        }
    } 

    repn(i,N/2){
        int sum=0;
        int index=N/2-i+1;
        do{
            sum+=ans[index];
            index+=N/2-i+1;
        }while(index<=N);
        //cout<<i<<' '<<sum<<endl;

        if(sum%2!=a[N/2-i+1]){
            ans[N/2-i+1]++;
            M++;
        }
    }

    cout<<M<<endl;
    repn(i,N){ 
        if(ans[i]==1){
            cout<<i<<' ';
        }
    }
}