#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;

int main(){
    cin>>N;

    int ans=0;
    for(int i=1;i<=N;i+=2){
        int x=i;
        int cnt=1;
        for(int j=2;j<=100;j++){
            int a=1;
            while(x%j==0){
                a++;
                x/=j;
            }
            if(a>0) cnt*=a;
        }
        if(cnt==8){
            ans++;
        }
    }

    cout<<ans<<endl;
}