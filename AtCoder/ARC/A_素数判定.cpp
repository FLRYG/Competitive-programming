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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;

int main(){
    cin>>N;
    
    bool flag=true;
    repn(i,sqrt(N)){
        if(i==1) continue;
        if(N%i==0){
            flag=false;
            break;
        }
    }
    if((N%10)%2!=0 && (N%10)%5!=0 && N%3!=0) flag=true;
    if(N==1) flag=false;

    if(flag){
        cout<<"Prime"<<endl;
    }else{
        cout<<"Not Prime"<<endl;
    }
}