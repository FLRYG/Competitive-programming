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
    SQ(): a(0), b(0), c(0), d(0){}
    SQ(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d){}
    ~SQ(){}
    SQ operator+=(const SQ &x){
        a+=x.a; b+=x.b; c+=x.c; d+=x.d;
        return (*this); 
    }
    SQ operator+(const SQ &x){ return (*this)+=x; }
    SQ operator-=(const SQ &x){
        a-=x.a; b-=x.b; c-=x.c; d-=x.d;
        return (*this); 
    }
    SQ operator-(const SQ &x){ return (*this)-=x; }
};

SQ unitsq[4]={SQ(-1,0,0,0),SQ(0,-1,0,0),SQ(0,0,1,0),SQ(0,0,0,1)};

int N;
IP A[200];
Timer timer;

ll computeScore(vector<SQ> &ans){
    double res=0;
    rep(i,N){
        if(ans[i].a<=A[i].second.first
        && A[i].second.first<ans[i].c
        && ans[i].b<=A[i].second.second
        && A[i].second.second<ans[i].d){
            int s=(ans[i].c-ans[i].a)*(ans[i].d-ans[i].b);
            res+=(1-pow(1-(double)min(A[i].first,s)/max(A[i].first,s),2))/N;
        }
    }
    return (ll)1e9*res;
}

void solve01(vector<SQ> &ans){
    rep(i,N){
        ans[i].a=A[i].second.first;
        ans[i].b=A[i].second.second;
        ans[i].c=A[i].second.first+1;
        ans[i].d=A[i].second.second+1;
    }

    ll prevScr=computeScore(ans);
    Random rand1(SEED,0,N-1);
    Random rand2(SEED,0,3);
    Random rand3(SEED,1,1000);
    // int cnt=0;
    while(timer.getTime()<4800){
        rep(n,500){
        // cnt++;
        int id=rand1.nextInt();
        int dir=rand2.nextInt();
        int dx=rand3.nextInt();
        // SQ tmp=(ans[id]+unitsq[d]);
        vector<SQ> tmp=ans;
        tmp[id]+=unitsq[dir];
        if(tmp[id].a>=0 && tmp[id].b>=0 && tmp[id].c<=10000 && tmp[id].d<=10000){
            switch(dir){
            case 0:
                rep(j,N) if(ans[id].a==ans[j].c) tmp[j].c--;
                break;
            case 1:
                rep(j,N) if(ans[id].b==ans[j].d) tmp[j].d--;
                break;
            case 2:
                rep(j,N) if(ans[id].c==ans[j].a) tmp[j].a++;
                break;
            case 3:
                rep(j,N) if(ans[id].d==ans[j].b) tmp[j].b++;
                break;
            }
            rep(j,N) if(tmp[j].a==tmp[j].c || tmp[j].b==tmp[j].d) continue;
            ll scr=computeScore(tmp);
            if(prevScr<scr){
                prevScr=scr;
                ans=tmp;
            }
        }
        }
    }
    // cout<<cnt<<endl;
}

void solve02(vector<SQ> &ans){
    vector<int> cnt(N,0);
    vector<vector<P>> hw(N,vector<P>(500));
    rep(i,N){
        cout<<i<<endl;
        repn(j,sqrt(A[i].first)){
            if(A[i].first%j==0){
                hw[i][cnt[i]].first=j;
                hw[i][cnt[i]++].second=A[i].first/j;
                cout<<"  "<<j<<' '<<A[i].first/j<<endl;
            }
        }
    }
    rep(i,N){
        ans[i].a=A[i].second.first-(hw[i][cnt[i]-1].first+1)/2;
        ans[i].b=A[i].second.second-(hw[i][cnt[i]-1].second+1)/2;
        ans[i].c=A[i].second.first+hw[i][cnt[i]-1].first/2;
        ans[i].d=A[i].second.second+hw[i][cnt[i]-1].second/2;
    }
}

int main(){
    timer.start();

    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>N;
    rep(i,N) cin>>A[i].second.first>>A[i].second.second>>A[i].first;

    vector<SQ> ans(N);
    // solve01(ans);
    solve02(ans);
    repr(e,ans){
        cout<<e.a<<' '<<e.b<<' '<<e.c<<' '<<e.d<<endl;
    }
    // rep(i,N){
    //     if(!(ans[i].a<ans[i].c && ans[i].b<ans[i].d)) cout<<i<<endl;
    // }
    // cout<<computeScore(ans)<<endl;
    
    return 0;
}