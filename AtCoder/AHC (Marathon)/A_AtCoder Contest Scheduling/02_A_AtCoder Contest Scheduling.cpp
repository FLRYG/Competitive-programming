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
//typedef pair<int,int> P;
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

struct Random{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
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

int D;
int c[26+1];
int s[365+1][26+1];

struct Score{
    int scr;
    vector<int> typescr;
    vector<set<int>> type2day;
    vector<int> scd;
    Score(vector<int> &_scd): scd(_scd){
        typescr=vector<int>(26,0);
        type2day=vector<set<int>>(26+1,set<int>());
        repn(i,26) type2day[i].insert(0);
        repn(d,scd.size()) type2day[scd[d]].insert(d);
        repn(i,26) type2day[i].insert(366);
        computeScore();
    }
    ~Score(){}
    void computeScore(){
        scr=0;
        repn(d,365){
            scr+=s[d][scd[d]];
            typescr[scd[d]]+=s[d][scd[d]];
        }
        repn(i,26) for(auto i1=type2day[i].begin(),i2=++type2day[i].begin();i2!=type2day[i].end();i1++,i2++){
            int n=(*i2)-(*i1);
            scr-=c[i]*n*(n-1)/2;
            typescr[i]-=c[i]*n*(n-1)/2;
        }
    }
    bool computeScore(int day, int type){
        int scr2=scr;
    }
};

void solve(vector<int> &ans){
    Random rnd_type(SEED,1,26);
    Random rnd_swap(SEED,1,365);

    rep(i,D) ans[i]=rnd_type.nextInt();
}

int main(){
    cin>>D;
    repn(i,26) cin>>c[i];
    repn(i,D) repn(j,26) cin>>s[i][j];

    vector<int> ans(D+1);
    solve(ans);
    
    return 0;
}