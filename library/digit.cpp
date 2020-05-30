#include <algorithm>
#include <cmath>
typedef long long ll;

inline ll digit(ll n){return log10(n)+1;}
ll digit_sum(ll n){
    ll res=0;
    ll ten=1;
    for(int i=1;i<=digit(n);i++){
        ten*=10;
        res+=n%ten;
    }
    return res;
}