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



int main(){
    int N;
    cin>>N;
    vector<int> perm(2*N-1);
    repn(i,2*N-1) perm[i-1]=i;
    vector<int> cnt(2*N);
    do{
        vector<int> v=perm;
        repn(i,N-1){
            rep(j,2*(i-1)) cout<<' ';
            rep(j,v.size()) cout<<v[j]<<' '; cout<<endl;
            vector<int> tmp(2*(N-i)-1);
            rep(j,2*(N-i)-1){
                vector<int> x;
                rep(k,3) x.push_back(v[j+k]);
                sort(x.begin(),x.end());
                tmp[j]=x[1];
            }
            v=tmp;
        }
        cnt[v[0]]++;
        rep(i,2*(N-1)) cout<<' ';
        cout<<v[0]<<endl<<endl;
    }while(next_permutation(perm.begin(),perm.end()));

    repn(i,2*N-1) cout<<i<<' '<<cnt[i]<<endl;
    
    return 0;
}