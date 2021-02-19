#include <iostream>
#include <bitset>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
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
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N;
ll A[200000];
ll B[200000];

int main(){
    cin>>N;
    vector<P> v;
    map<P,P> m;
    ll zero=0;
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        if(a==0 && b==0){
            zero++;
            continue;
        }
        ll g=gcd(a,b);
        a/=g;
        b/=g;
        if(b<0){
            a*=-1;
            b*=-1;
        }else if(b==0 && a<0){
            a*=-1;
        }
        if(a>0) m[P(a,b)].first++;
        else m[P(b,-a)].second++;
    }

    ll ans=1;
    repr(e,m){
        ans*=(mpow(2,e.second.first)+mpow(2,e.second.second)-1)%MOD;
        ans%=MOD;
    }
    ans=ans-1+zero;
    ans=(ans+MOD)%MOD;

    cout<<ans<<endl;

    return 0;
}

// ll N;
// ll A[200000];
// ll B[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>A[i]>>B[i];

//     rep(i,N){
//         if(A[i]!=0 && B[i]!=0){
//             ll g=gcd(A[i],B[i]);
//             A[i]/=g;
//             B[i]/=g;
//         }
//     }
    
//     map<P,P> m;
//     rep(i,N) m[P(A[i],B[i])].first++;

//     ll ans=1;
//     rep(i,N){
//         if(A[i]==0 && B[i]==0) continue;
//         if(m[P(A[i],B[i])].second) continue;
//         ll cnt1=m[P(A[i],B[i])].first+m[P(-A[i],-B[i])].first;
//         ll cnt2=m[P(B[i],-A[i])].first+m[P(-B[i],A[i])].first;
//         ans*=(mpow(2,cnt1)+mpow(2,cnt2)-1)%MOD;
//         ans%=MOD;
//         m[P(A[i],B[i])].second=1;
//         m[P(-A[i],-B[i])].second=1;
//         m[P(B[i],-A[i])].second=1;
//         m[P(-B[i],A[i])].second=1;
//     }
//     ans--;
//     ans+=m[P(0,0)].first;
//     ans%=MOD;
//     if(ans<0) ans+=MOD;
    
//     cout<<ans<<endl;

//     return 0;
// }

// ll N;
// ll A[200000];
// ll B[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>A[i]>>B[i];

//     // int anss=0;
//     // vector<int> v(N);
//     // int x=1;
//     // repn(i,(1<<N)-1){
//     //     if(i>>0&1) cout<<bitset<10>(i)<<' '<<x++<<' ';
//     //     int idx=-1;
//     //     rep(j,N){
//     //         if(i>>j&1){
//     //             if(idx==-1) idx=j;
//     //             rep(k,N){
//     //                 if(i>>k&1 && A[j]*A[k]+B[j]*B[k]==0){
//     //                     if(i>>0&1) cout<<endl;
//     //                     goto a;
//     //                 }
//     //             }
//     //         }
//     //     }
//     //     // if(idx==0) cout<</*x++<<": "<<*/bitset<10>(i)<<' '<<x++<<endl;
//     //     if(idx==0) cout<<'o'<<endl;
//     //     v[idx]++;
//     //     anss++;
//     //     a:;
//     // }
//     // cout<<anss<<endl;
//     // rep(i,N) cout<<i+1<<' '<<v[i]<<endl;

//     rep(i,N){
//         if(A[i]!=0 && B[i]!=0){
//             ll g=gcd(abs(A[i]),abs(B[i]));
//             A[i]/=g;
//             B[i]/=g;
//         }
//     }

//     // cout<<endl;
//     // rep(i,N){
//     //     cout<<i+1<<' '<<A[i]<<' '<<B[i]<<endl;
//     // }
//     // cout<<endl;
    
//     map<P,P> m;
//     rep(i,N) m[P(A[i],B[i])].first++;

//     ll ans=1;
//     ll n=N;
//     rep(i,N){
//         if(A[i]==0 && B[i]==0) n--;
//         if(m[P(A[i],B[i])].second) continue;
//         ll cnt1=m[P(A[i],B[i])].first;
//         ll cnt2=m[P(B[i],-A[i])].first+m[P(-B[i],A[i])].first;
//         if(cnt2>0){
//             ans*=(mpow(2,cnt1)+mpow(2,cnt2)-1)%MOD;
//             ans%=MOD;
//             n-=cnt1+cnt2;
//             m[P(A[i],B[i])].second=1;
//             m[P(B[i],-A[i])].second=1;
//             m[P(-B[i],A[i])].second=1;
//         }
//     }
//     ans*=mpow(2,n);
//     ans%=MOD;
//     ans--;
//     ans+=m[P(0,0)].first;
//     ans%=MOD;
//     if(ans<0) ans+=MOD;

//     // ll zero=m[P(0,0)].first;
//     // ll ans=zero;
//     // ll idx=0;
//     // rep(i,N){
//     //     if(A[i]==0 && B[i]==0) continue;
//     //     if(m[P(A[i],B[i])].second) continue;
//     //     ll cnt=m[P(B[i],-A[i])]+m[P(-B[i],A[i])];
//     //     ans+=mpow(2,N-zero-idx-1-cnt);
//     //     cout<<i+1<<' '<<cnt<<' '<<mpow(2,N-zero-idx-1-cnt)<<endl;
//     //     ans%=MOD;
//     //     idx++;
//     //     m[P(A[i],B[i])]--;
//     // }
    
//     cout<<ans<<endl;

//     return 0;
// }

// ll sign(ll A){
//     return A>0?1:A<0?-1:0;
// }

// ll N;
// ll A[200000];
// ll B[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>A[i]>>B[i];
//     vector<ll> C(N);
//     rep(i,N) C[i]=sign(A[i])*sign(B[i]);
//     rep(i,N) A[i]=abs(A[i]);
//     rep(i,N) B[i]=abs(B[i]);
//     rep(i,N){
//         if(C[i]==0) continue;
//         ll g=gcd(A[i],B[i]);
//         A[i]/=g;
//         B[i]/=g;
//     }

//     ll ans=mpow(2,N)-1;
//     map<PP,ll> m;
//     ll a=0, b=0, zero=0;
//     rep(i,N){
//         if(A[i]==0 && B[i]==0) zero++;
//         else if(A[i]==0) a++;
//         else if(B[i]==0) b++;
//         else m[PP(P(A[i],B[i]),C[i])]++;
//     }
//     ans-=zero*(mpow(2,N-zero)-1);
//     ans%=MOD;
//     N-=zero;
//     ans-=a*b%MOD*(mpow(2,N-a-b)-1);
//     ans%=MOD;

//     ans-=(mpow(2,zero)-1)*(mpow)
//     repr(e,m){
//         if(e.second==INF) continue;
//         ll x=e.second;
//         ll y=m[PP(P(e.first.first.second,e.first.first.first),-e.first.second)]
//         ans-=e.first.second
//     }
    
//     return 0;
// }


// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <queue>
// #include <deque>
// #include <map>
// #include <unordered_map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// #define repr(e,x) for(auto& e:x)
// using namespace std;
// typedef long long ll;
// typedef pair<ll,pair<ll,ll>> P;

// const ll MOD=1'000'000'007;

// template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}

// ll mpow(ll x,ll n){
//     if(n==0) return 1;
//     else if(n%2) return x*mpow(x,n-1)%MOD;
//     return mpow(x*x%MOD,n/2)%MOD;
// }

// ll mfrac(ll n){
//     if(n==0) return 1;
//     else return n*mfrac(n-1)%MOD;
// }

// ll mperm(ll n,ll r){
//     ll res=1;
//     for(ll i=0;i<r;i++) res=res*(n-i)%MOD;
//     return res;
// }

// ll mcomb(ll n,ll r){
//     if(r>n-r) r=n-r;
//     ll res=mperm(n,r);
//     return res*mpow(mfrac(r),MOD-2)%MOD;
// }

// ll N;
// map<P,ll> m;

// int main(){
//     cin>>N;
//     rep(i,N){
//         ll a,b;
//         cin>>a>>b;
//         ll g=gcd(a,b);
//         a/=g;
//         b/=g;
//         ll sign=a^b?-1:(a==0 && b==0)?0:1;
//         P p(sign,pair<ll,ll>(a,b));
//         m[p]++;
//     }

//     ll ans=mpow(2,N);
//     repr(e,m){
//         if(e.first.first>0){
//             ll cnt1=e.second;
//             ll cnt2=m[P(-1,pair<ll,ll>(e.first.second.second,e.first.second.first))];
            
//         }
//     }
//     if(ans<0) ans+=MOD;

//     cout<<ans<<endl;
// }