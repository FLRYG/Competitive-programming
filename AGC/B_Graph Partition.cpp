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
string s[200];

int main(){
    cin>>N;
    rep(i,N) cin>>s[i];

    int ans=-1;
    rep(start,N){
        vector<int> num(N,0);
        int v=1;
        num[start]=v;
        vector<int> tmp;
        queue<int> q;
        q.push(start);
        q.push(-1);
        while(!q.empty()){
            int p=q.front(); q.pop();
            //cout<<p<<endl;
            if(p==-2) break;
            if(p==-1){
                //repr(e,tmp) cout<<e<<' ';cout<<endl;
                repr(e1,tmp){
                    repr(e2,tmp){
                        if(s[e1][e2]=='1'){
                            //cout<<"break"<<endl;
                            goto a;
                        }
                    }
                }
                if(!q.empty()){
                    v++;
                    repr(e,tmp){
                        num[e]=v;
                    }
                    tmp.clear();
                    q.push(-1);
                }else{
                    break;
                }
                continue;
            }
            rep(i,N){
                if(s[p][i]=='1' && num[i]==0){
                    num[i]=INF;
                    q.push(i);
                    tmp.push_back(i);
                }
            }
        }
        //cout<<start<<' '<<v<<endl;
        //rep(i,N) cout<<num[i]<<' ';cout<<endl;
        ans=max(ans,v);
        a:;
    }

    cout<<ans<<endl;
}