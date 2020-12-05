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

int N;
int P[200001];
int idx[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>P[i];

    repn(i,N) idx[P[i]]=i;

    vector<int> ans(N);
    vector<int> s(N-1);
    int cnt=0;
    repn(i,N){
        if(cnt>N-1) break;
        for(int j=idx[i];j>i;j--){
            if(cnt>N-1) break;
            int tmp=P[j-1];
            P[j-1]=P[j];
            P[j]=tmp;
            idx[P[j]]=j;
            idx[P[j-1]]=j-1;
            ans[cnt]=j-1;
            cnt++;
            s[j-1]++;
        }
    }

    repn(i,N-1){
        if(s[i]!=1){
            cout<<-1<<endl;
            return 0;
        }
    }
    repn(i,N){
        if(i!=P[i]){
            cout<<-1<<endl;
            return 0;
        }
    }

    rep(i,N-1){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}