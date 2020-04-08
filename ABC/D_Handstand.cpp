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

int N,K;
string S;
int t[100000];

int main(){
    cin>>N>>K>>S;
    
    int num=S[0];
    int index=0;
    rep(i,N){
        if(num==S[i]) t[index]++;
        else{
            t[++index]++;
            num=(num+1)%2;
        }
    }
    index++;
    
    int sign=S[0];
    if((index%2==0 || (index%2==1 && sign==1)) && index/2<=K){
        cout<<N<<endl;
        return 0;
    }else if(index%2==1 && sign==0 && index/2+1<=K){
        cout<<N<<endl;
        return 0;
    }

    int ans=0;
    rep(i,index){
        if(i%2==)
    }


    


}