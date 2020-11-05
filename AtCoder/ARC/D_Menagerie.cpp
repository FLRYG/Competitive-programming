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

int I[]={1,1,-1,-1};
int J[]={1,-1,1,-1};
int N;
string s;

int main(){
    cin>>N>>s;

    vector<int> v(N+1,0);
    rep(n,4){
        v[0]=I[n];
        v[1]=J[n];
        repn(i,N-1){
            if(v[i]==1){
                if(s[i]=='o') v[i+1]=v[i-1];
                if(s[i]=='x') v[i+1]=-v[i-1];
            }else if(v[i]==-1){
                if(s[i]=='o') v[i+1]=-v[i-1];
                if(s[i]=='x') v[i+1]=v[i-1];
            }
        }
        if(v[0]==v[N] && ((v[0]==1 && s[0]=='o' && v[N-1]==v[1]) 
        || (v[0]==1 && s[0]=='x' && v[N-1]==-v[1])
        || (v[0]==-1 && s[0]=='x' && v[N-1]==v[1]) 
        || (v[0]==-1 && s[0]=='o' && v[N-1]==-v[1]))){
            //cout<<n<<endl;
            //repr(e,v) cout<<e<<' ';cout<<endl; 
            rep(i,N){
                if(v[i]==1) cout<<'S';
                else cout<<'W';
            }
            cout<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
}