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

int N,M;
int P[100000];
int Y[100000];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>P[i]>>Y[i], P[i]--;

    vector<vector<int>> v(N);
    rep(i,M){
        v[P[i]].push_back(Y[i]);
    }

    rep(i,N){
        sort(v[i].begin(),v[i].end());
    }

    rep(i,M){
        int x=(int)(lower_bound(v[P[i]].begin(),v[P[i]].end(),Y[i])-v[P[i]].begin())+1;
        printf("%06d%06d\n",P[i]+1,x);
    }
    
    return 0;
}

// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <queue>
// #include <unordered_map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// using namespace std;
// typedef long long ll;


// int N,M;
// pair<pair<int,int>,int> PY[100000];
// string ans[100000];

// void addans(int pre,int index,int i){
//     string res;
//     string s1=to_string(pre);
//     rep(i,6-s1.size()) res+="0";
//     res+=s1;
//     string s2=to_string(index);
//     rep(i,6-s2.size()) res+="0";
//     res+=s2;
//     ans[i]=res;
// }

// int main(){
//     cin>>N>>M;
//     rep(i,M){
//         int p,y;
//         cin>>p>>y;
//         PY[i].first.first=p;
//         PY[i].first.second=y;
//         PY[i].second=i;
//     }

//     sort(PY,PY+M);
    
//     /*rep(i,M){
//         cout<<PY[i].first.first<<' '<<PY[i].first.second<<' '<<PY[i].second<<endl;
//     }*/

//     int pre=0, index=1;
//     rep(i,M){
//         if(PY[i].first.first==pre){
//             addans(pre,index,PY[i].second);
//         }else{
//             pre=PY[i].first.first;
//             index=1;
//             addans(pre,index,PY[i].second);
//         }
//         index++;
//     }

//     rep(i,M){
//         cout<<ans[i]<<endl;
//     }
// }