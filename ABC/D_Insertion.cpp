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
string S;

int main(){
    cin>>N>>S;

    int l=0, r=0;
    rep(i,N){
        if(S[i]=='(') l++;
        else if(l>0) l--;
        else r++;
    }

    string ans;
    rep(i,r) ans+='(';
    ans+=S;
    rep(i,l) ans+=')';

    cout<<ans<<endl;
}

/*
int main(){
    cin>>N>>S;

    int L=0;
    map<int,int,greater<int>> m;
    char prev=')';
    int l=0, r=0;
    rep(i,N){
        if(S[i]==')'){
            l++;
            prev=')';
        }
        if(S[i]=='('){
            if(prev==')'){
                if(l>r){
                    L+=l-r;
                }else if(r>l){
                    m[i]+=r-l;
                }
                l=0;r=0;
            }
            r++;
            prev='(';
        }
    }
    if(l>r){
        L+=l-r;
    }else if(r>l){
        m[N]+=r-l;
    }

    repr(e,m){
        rep(i,e.second) S.insert(e.first,")");
    }
    rep(i,L) S.insert(0,"(");

    cout<<S<<endl;
}
*/

/*
int main(){
    cin>>N>>S;

    int l=0, r=0;
    rep(i,N){
        if(S[i]==')') l++;
        else break;
    }
    rep(i,N){
        if(S[N-i-1]=='(') r++;
        else break;
    }
    cout<<l<<' '<<r<<endl;
    int L=0,R=0;
    rep(i,N-(l+r)){
        if(S[i+l]==')') L++;
        if(S[i+l]=='(') R++;
    }
    cout<<L<<' '<<R<<endl;
    l+=max(0,L-R);
    r+=max(0,R-L);
    

    string ans;
    rep(i,l) ans+='(';
    ans+=S;
    rep(i,r) ans+=')';

    cout<<ans<<endl;
}
*/