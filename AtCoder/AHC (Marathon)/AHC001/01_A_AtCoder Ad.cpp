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

int N;
// IP rxy[200];
Timer timer;

struct Rect{
    int x,y,r;
    int a,b,c,d;
    Rect(){}
    Rect(int _x, int _y ,int _r):x(_x), y(_y), r(_r), a(0), b(0), c(1), d(1){}
    Rect(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d){}
    ~Rect(){}
    // Rect operator+=(Rect const &x){
    //     a+=x.a; b+=x.b; c+=x.c; d+=x.d;
    //     return (*this); 
    // }
    // Rect operator+(Rect const &x){ return (*this)+=x; }
    // Rect operator-=(Rect const &x){
    //     a-=x.a; b-=x.b; c-=x.c; d-=x.d;
    //     return (*this); 
    // }
    // Rect operator-(Rect const &x){ return (*this)-=x; }
    bool overlap(Rect const &sq){
        if(max(c,sq.c)-min(a,sq.a)<c-a+sq.c-sq.a
        && max(d,sq.d)-min(b,sq.b)<d-b+sq.d-sq.b) return true;
        return false;
    }
    int area(){ return (c-a)*(d-b); }
    bool include(int const &_x, int const &_y){ 
        return (a<=_x && x<c && b<=_y && y<d);
    }
    void expand(int const &dir, int const &dx){
        if(dir==0) a=max(0,a-dx);
        else if(dir==1) b=max(0,b-dx);
        else if(dir==2) c=min(10000,c+dx);
        else if(dir==3) d=min(10000,d+dx);
    }
    bool move(int const &dir, int const &dx){
        if(dir==0 && dx<=a) a-=dx, c-=dx;
        else if(dir==1 && dx<=b) b-=dx, d-=dx;
        else if(dir==2 && dx+c<=10000) a+=dx, c+=dx;
        else if(dir==3 && dx+d<=10000) b+=dx, d+=dx;
        else return false;
        return true;
    }
    ll socre(){
        double res=0;
        if(a<=x && x<c && b<=y && y<d){
            int s=(c-a)*(d-b);
            res=(1-pow(1-(double)min(r,s)/max(r,s),2))/N;
        }
        return (ll)1e9*res;
    }
};

Rect unitRect[4]={Rect(-1,0,0,0),Rect(0,-1,0,0),Rect(0,0,1,0),Rect(0,0,0,1)};

ll computeScore(vector<Rect> &ans){
    double res=0;
    rep(i,N){
        if(ans[i].a<=ans[i].x
        && ans[i].x<ans[i].c
        && ans[i].b<=ans[i].y
        && ans[i].y<ans[i].d){
            int s=(ans[i].c-ans[i].a)*(ans[i].d-ans[i].b);
            res+=(1-pow(1-(double)min(ans[i].r,s)/max(ans[i].r,s),2))/N;
        }
    }
    return (ll)1e9*res;
}

void solve01(vector<Rect> &ans){
    rep(i,N){
        ans[i].a=ans[i].x;
        ans[i].b=ans[i].y;
        ans[i].c=ans[i].x+1;
        ans[i].d=ans[i].y+1;
    }

    Random rand1(SEED,0,N-1);
    Random rand2(SEED,0,1<<30);
    Random rand3(SEED,0,1);
    // int cnt=0, cnt2=0;
    // vector<int> cnt3(N,0);
    // vector<int> cnt4(4,0);
    while(timer.getTime()<4900){
        rep(i,1000){

        // cnt++;
        int id=rand1.nextInt();
        ll dir=rand2.nextInt();
        int flagnum=rand3.nextInt();
        // cnt3[id]++;
        // cnt4[dir]++;

        Rect prevRect=ans[id];
        if(flagnum>0){
            ll prevScr=ans[id].socre();
            ll h=ans[id].c-ans[id].a;
            ll w=ans[id].d-ans[id].b;
            if(dir<=(1<<30)*w/(h+w)){
                if(dir&1) dir=0;
                else dir=2;
            }else{
                if(dir&1) dir=1;
                else dir=3;
            }
            ans[id].expand(dir,1);
            bool flag=true;
            rep(i,N){
                if(i==id) continue;
                if(ans[id].overlap(ans[i])){
                    ans[id]=prevRect;
                    flag=false;
                    break;
                }
            }
            if(flag){
                ll scr=ans[id].socre();
                if(scr>prevScr) prevScr=scr;// cnt2++;
                else ans[id]=prevRect;
            }else{
                ans[id]=prevRect;
            }
        }else{
            if(!ans[id].move(dir%4,1)) continue;
            if(!ans[id].include(ans[id].x,ans[id].y)){
                ans[id]=prevRect;
                continue;
            }
            bool flag=true;
            rep(i,N){
                if(i==id) continue;
                if(ans[id].overlap(ans[i])){
                    ans[id]=prevRect;
                    flag=false;
                    break;
                }
            }
            if(!flag) ans[id]=prevRect;
        }
        
        }
    }
    // cout<<cnt<<endl;
    // rep(i,N) cout<<i<<' '<<cnt3[i]<<endl;
    // rep(i,4) cout<<i<<' '<<cnt4[i]<<endl;
}

int main(){
    timer.start();

    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin>>N;
    vector<Rect> ans(0);
    ans.reserve(N);
    rep(i,N){
        int x,y,r;
        cin>>x>>y>>r;
        ans.push_back(Rect(x,y,r));
    }

    solve01(ans);

    repr(e,ans){
        cout<<e.a<<' '<<e.b<<' '<<e.c<<' '<<e.d<<endl;
    }

    // rep(i,N){
    //     cout<<i<<' '<<ans[i].socre()<<endl;
    // }
    // cout<<computeScore(ans)<<endl;
    
    return 0;
}