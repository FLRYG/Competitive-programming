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

int N;
string C;
string table[4]={"A","B","X","Y"};

int main(){
    cin>>N>>C;

    int ans=1001001001;
    rep(i,16){
        rep(j,16){
            string s1=table[i/4]+table[i%4];
            string s2=table[j/4]+table[j%4];
            int res=0;
            rep(k,N){
                res++;
                if(k==N-1) break;
                string s;
                s+=C[k];
                s+=C[k+1];
                if(s1==s || s2==s) k++;
            }
            //cout<<s1<<' '<<s2<<' '<<res<<endl;
            ans=min(ans,res);
        }
    }

    cout<<ans<<endl;
}