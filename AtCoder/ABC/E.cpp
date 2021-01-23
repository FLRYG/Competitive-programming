#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

struct Mat{
    vector<ll> v;
    Mat(){
        v=vector<ll>(9);
        v[0]=v[4]=v[8]=1;
    }
    Mat(ll x){
        v=vector<ll>(9,x);
    }
    Mat(vector<ll> v_){
        v=v_;
    };
    ll& operator[](size_t k){return v[k];}
    Mat prod(Mat B){
        vector<ll> w(9);
        rep(i,3){
            rep(j,3){
                rep(k,3){
                    w[i*3+j]+=v[i*3+k]*B[k*3+j];
                }
            }
        }
        return Mat(w);
    }
    Mat f1(){
        Mat w(0);
        w[1]=1;
        w[3]=-1;
        w[8]=1;
        return w.prod(v);
    }
    Mat f2(){
        Mat w(0);
        w[1]=-1;
        w[3]=1;
        w[8]=1;
        return w.prod(v);
    }
    Mat f3(ll p){
        Mat w(0);
        w[0]=-1;
        w[2]=2*p;
        w[4]=1;
        w[8]=1;
        return w.prod(v);
    }
    Mat f4(ll p){
        Mat w(0);
        w[0]=1;
        w[5]=2*p;
        w[4]=-1;
        w[8]=1;
        return w.prod(v);
    }
    vector<ll> prod2(vector<ll> &vec){
        vector<ll> res(3);
        rep(i,3){
            rep(j,3){
                res[i]+=v[i*3+j]*vec[j];
            }
        }
        return res;
    }
};

ll N,M,Q;
ll X[200000];
ll Y[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];
    
    cin>>M;
    vector<Mat> v(M+1);
    repn(i,M){
        int op;
        cin>>op;
        if(op==1) v[i]=v[i-1].f1();
        else if(op==2) v[i]=v[i-1].f2();
        else{
            int p;
            cin>>p;
            if(op==3) v[i]=v[i-1].f3(p);
            if(op==4) v[i]=v[i-1].f4(p);
        }
    }
    // rep(k,M+1){
    //     rep(i,3){
    //         rep(j,3){
    //             cout<<v[k][i*3+j]<<' ';
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    cin>>Q;
    vector<ll> res;
    rep(i,Q){
        ll A,B;
        cin>>A>>B;
        B--;
        vector<ll> vv(3,1);
        vv[0]=X[B];
        vv[1]=Y[B];
        res=v[A].prod2(vv);
        cout<<res[0]<<' '<<res[1]<<endl;
    }
    
    return 0;
}