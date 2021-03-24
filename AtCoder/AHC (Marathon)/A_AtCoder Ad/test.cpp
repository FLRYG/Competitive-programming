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

// タイマー(ミリ秒)
struct Timer{
    private:
    double starttime;
    inline double nowTime() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    public:
    Timer(){}
    ~Timer(){}
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

struct Rect{
    int x,y,r;
    int a,b,c,d;
    Rect(){}
    Rect(int _x, int _y ,int _r):x(_x), y(_y), r(_r), a(0), b(0), c(1), d(1){}
    Rect(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d){}
    ~Rect(){}
    Rect operator+=(Rect const &x){
        a+=x.a; b+=x.b; c+=x.c; d+=x.d;
        return (*this); 
    }
    Rect operator+(Rect const &x){ return (*this)+=x; }
    Rect operator-=(Rect const &x){
        a-=x.a; b-=x.b; c-=x.c; d-=x.d;
        return (*this); 
    }
    Rect operator-(Rect const &x){ return (*this)-=x; }
    bool overlap(Rect const &sq){
        if(max(c,sq.c)-min(a,sq.a)<c-a+sq.c-sq.a
        && max(d,sq.d)-min(b,sq.b)<d-b+sq.d-sq.b) return true;
        return false;
    }
    int area(){ return (c-a)*(d-b); }
    void expand(int dir, int dx){
        if(dir==0) a=max(0,a-dx);
        else if(dir==1) b=max(0,b-dx);
        else if(dir==2) c=min(10000,c+dx);
        else if(dir==3) d=min(10000,d+dx);
    }
    // ll socre(){
    //     double res=0;
    //     if(a<=x && x<c && b<=y && y<d){
    //         int s=(c-a)*(d-b);
    //         res=(1-pow(1-(double)min(r,s)/max(r,s),2))/N;
    //     }
    //     return (ll)1e9*res;
    // }
};

Rect unitRect[4]={Rect(-1,0,0,0),Rect(0,-1,0,0),Rect(0,0,1,0),Rect(0,0,0,1)};

int main(){
    int N=100000;
    Timer t;

    t.start();
    rep(i,N) t.getTime();
    cout<<t.getTime()<<endl;

    int x=0;
    t.start();
    rep(i,N) x++;
    cout<<t.getTime()<<endl;

    t.start();
    rep(i,N) if(x==i) x++;
    cout<<t.getTime()<<endl;

    t.start();
    rep(i,N) i%200;
    cout<<t.getTime()<<endl;

    Random r(0,0,99);
    t.start();
    rep(i,N) r.nextInt();
    cout<<t.getTime()<<endl;

    Rect rec(100,100,101,101);
    rep(i,5){
        rec+=unitRect[0];
        cout<<rec.a<<' '<<rec.b<<' '<<rec.c<<' '<<rec.d<<endl;
    }

    rep(i,5){
        rec+=unitRect[1];
        cout<<rec.a<<' '<<rec.b<<' '<<rec.c<<' '<<rec.d<<endl;
    }

    rep(i,5){
        rec+=unitRect[2];
        cout<<rec.a<<' '<<rec.b<<' '<<rec.c<<' '<<rec.d<<endl;
    }

    rep(i,5){
        rec+=unitRect[3];
        cout<<rec.a<<' '<<rec.b<<' '<<rec.c<<' '<<rec.d<<endl;
    }

    return 0;
}