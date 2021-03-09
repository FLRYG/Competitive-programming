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
typedef pair<int,int> P;
typedef pair<int,P> IP;
typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;
int const SEED=121314;

// タイマー(ミリ秒)
struct Timer{
    double starttime;
    Timer(){}
    ~Timer(){}
    inline double nowTime() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    inline void start(){
        starttime=nowTime();
    }
    inline double getTime(){
        return nowTime()-starttime;
    }
};

// 整数の乱数を[a,b]の範囲で返す
struct Random{
    private:
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    public:
    Random(int _seed, int _min, int _max): seed(_seed),min(_min),max(_max){
        mt.seed(seed);
        uniform_int_distribution<int>::param_type param(min,max);
        rand.param(param);
    }
    ~Random(){}
    int nextInt(){
        return rand(mt);
    }
};

struct SQ{
    int a,b,c,d;
    SQ()
};

int N;
IP A[200];
Timer timer;

ll computeScore(vector<PP> &ans){
    double res=0;
    rep(i,N){
        if(ans[i].first.first<=A[i].second.first
        && A[i].second.first<ans[i].second.first
        && ans[i].first.second<=A[i].second.second
        && A[i].second.second<ans[i].second.second){
            int s=(ans[i].second.first-ans[i].first.first)*(ans[i].second.second-ans[i].first.second);
            res+=(1-pow(1-(double)min(A[i].first,s)/max(A[i].first,s),2))/N;
        }
    }
    return (ll)1e9*res;
}

void solve01(vector<PP> &ans){
    rep(i,N){
        ans[i].first.first=A[i].second.first;
        ans[i].first.second=A[i].second.second;
        ans[i].second.first=A[i].second.first+1;
        ans[i].second.second=A[i].second.second+1;
    }

    ll prevScr=computeScore(ans);
    Random rand1(SEED,0,N-1);
    Random rand2(SEED,0,3);
    while(timer.getTime()<4800){
        int idx=rand1.nextInt();
        int d=rand2.nextInt();
        if()
    }
}

int main(){
    timer.start();

    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>N;
    rep(i,N) cin>>A[i].second.first>>A[i].second.second>>A[i].first;

    vector<PP> ans(N);
    solve01(ans);
    repr(e,ans){
        cout<<e.first.first<<' '<<e.first.second<<' '<<e.second.first<<' '<<e.second.second<<endl;
    }
    
    return 0;
}