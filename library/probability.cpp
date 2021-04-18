#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

// 保留
// const int MAX = 510000;
// ll fac[MAX], finv[MAX], inv[MAX];

// // テーブルを作る前処理
// void COMinit() {
//     fac[0]=fac[1]=1;
//     finv[0]=finv[1]=1;
//     inv[1]=1;
//     for (int i=2; i < MAX; i++){
//         fac[i]=fac[i - 1] * i % MOD;
//         inv[i]=MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i]=finv[i - 1] * inv[i] % MOD;
//     }
// }

// // 二項係数計算
// ll COM(int n, int k){
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1)%MOD;
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i)%MOD;
    return res;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res*mpow(mfrac(r),MOD-2)%MOD;
}

//パスカルの三角形を利用
ll pcomb(ll n, ll r){
    vector<vector<ll>> v(n+1,vector<ll>(n+1,0));
    for(int i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k = 1;k <v.size();k++){
        for(int j = 1;j<k;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }
    return v[n][r];
}


int main(){
    cout<<mfrac(13)<<endl;
}

