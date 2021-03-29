#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int mpow(int x,int n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

int M,K;

int main(){
    cin>>M>>K;

    if(M==1 && K>0){
        cout<<-1<<endl;
        return 0;
    }
    if(mpow(2,M)<=K){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> ans(mpow(2,M+1),0);
    if(K==0) rep(i,mpow(2,M)) ans[i]=ans[ans.size()-1-i]=i;
    else{
        int j=1;
        ans[0]=0;
        ans[mpow(2,M)-1]=0;
        ans[mpow(2,M)]=K;
        ans[mpow(2,M+1)-1]=K;
        rep(i,mpow(2,M)){
            if(i==0 || i==K) continue;
            ans[j]=i;
            ans[ans.size()-1-j]=i;
            j++;
        }
    }

    repr(e,ans) cout<<e<<' '; cout<<endl;
    
    return 0;
}