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

ll D;
ll c[26+1];
ll s[365+1][26+1];

ll last[365+1];

void input(){
    cin>>D;
    repn(i,26) cin>>c[i];
    repn(i,D) repn(j,26) cin>>s[i][j];
}

int main(){
    input();

    /*ll v=0;
    repn(d,D){
        ll maxi=0;
        ll k=0;
        repn(i,26){
            if(maxi<=s[d][i]){
                maxi=s[d][i];
                k=i;
            }
        }
        v+=maxi;
        last[k]=d;
        repn(i,26) v-=c[i]*(d-last[i]);
        cout<<k<<endl;
    }*/

    repn(d,D){
        ll maxi=0;
        ll idx=0;
        repn(i,26){
            ll sum=s[d][i];
            repn(j,26){
                if(i==j) continue;
                sum-=c[j]*(d-last[j]);
            }
            if(sum>=maxi){
                idx=i;
                maxi=sum;
            }
        }
        last[idx]=d;
        cout<<idx<<endl;
    }
}

/*
int main(){
    input();

    ll v=0;
    repn(d,D){
        ll maxi=0;
        ll k=0;
        repn(i,26){
            if(maxi<=s[d][i]){
                maxi=s[d][i];
                k=i;
            }
        }
        v+=maxi;
        last[k]=d;
        repn(i,26) v-=c[i]*(d-last[i]);
        cout<<k<<endl;
    }
}
*/