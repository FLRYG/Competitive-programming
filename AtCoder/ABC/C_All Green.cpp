// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <queue>
// #include <deque>
// #include <unordered_map>
// #include <map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// using namespace std;
// typedef long long ll;

// int D,G;
// int p[100],c[100];

// int main(){
//     cin>>D>>G;
//     rep(i,D) cin>>p[i]>>c[i];

//     int ans=1001001001;
//     for(int i=0;i<1<<D;i++){
//         int g=G;
//         int res=0;
//         int maximum;
//         for(int j=0;j<D;j++){
//             if(i>>j&1){
//                 res+=p[j];
//                 g-=(100*(j+1)*p[j]+c[j]);
//             }else{
//                 maximum=j;
//             }
//         }
        
//         if(g<=0){
//             ans=min(ans,res);
//         }else{
//             if(g/(100.0*(maximum+1))<=p[maximum]){
//                 res+=ceil(g/(100.0*(maximum+1)));
//                 ans=min(ans,res);
//             }
//         }
//     }

//     cout<<ans<<endl;
// }



#include <iostream>
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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int D,G;
int p[10];
int c[10];

int main(){
    cin>>D>>G;
    rep(i,D) cin>>p[i]>>c[i];

    int ans=INF;
    rep(i,1<<D){
        int scr=0, cnt=0;
        int k=-1;
        rep(j,D){
            if(i>>j&1){
                scr+=(j+1)*p[j]*100+c[j];
                cnt+=p[j];
            }else{
                k=j;
            }
        }
        if(scr<G && k!=-1){
            if((G-scr+(k+1)*100-1)/((k+1)*100)<p[k]){
                cnt+=(G-scr+(k+1)*100-1)/((k+1)*100);
            }else{
                continue;
            }
        }
        ans=min(ans,cnt);
    }

    cout<<ans<<endl;
    
    return 0;
}