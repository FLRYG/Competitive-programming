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

ll D;
ll c[26+1];
ll s[365+1][26+1];

ll last[365+1];

void input(){
    cin>>D;
    repn(i,26) cin>>c[i];
    repn(i,D) repn(j,26) cin>>s[i][j];
}

// 貪欲法 62,634,806
void solve1(){
    repn(d,D){
        ll maxi=-LINF;
        ll idx=0;
        repn(i,26){
            ll res=0;
            res+=s[d][i];
            repn(j,26){
                if(i==j) continue;
                res-=c[j]*(d-last[j]);
            }
            if(maxi<res){
                maxi=res;
                idx=i;
            }
        }
        last[idx]=d;
        cout<<idx<<endl;
    }
}

// 貪欲法2
void solve2(){
    ll v[27][400];
    ll max_score=-LINF;
    ll max_idx=0;
    rep(k,27){
        ll score=0;
        fill(last,last+27,0);
        repn(d,D+k){
            ll maxi=-LINF;
            ll idx=0;
            repn(i,26){
                ll res=0;
                if(d<=D) res+=s[d][i];
                repn(j,26){
                    if(i==j) continue;
                    res-=c[j]*(d-last[j]);
                }
                if(maxi<res){
                    maxi=res;
                    idx=i;
                }
            }
            last[idx]=d;
            score+=maxi;
            v[k][d]=idx;
        }
        if(max_score<score){
            max_score=score;
            max_idx=k;
        }
    }

    repn(i,D){
        cout<<v[max_idx][i]<<endl;
    }  
}

int main(){
    input();
    solve2();
}