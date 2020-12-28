#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;
ll const SEED=121314;

#include <chrono>
// タイマー
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

ll D;
ll c[26+1];
ll s[365+1][26+1];

void input(){
    cin>>D;
    repn(i,26) cin>>c[i];
    repn(i,D) repn(j,26) cin>>s[i][j];
}

// 貪欲
// 62,634,806
void solve1(){
    vector<ll> ans(D+1);
    vector<ll> last(26+1,0);
    repn(d,D){
        ll sum=0;
        repn(i,26){
            sum-=c[i]*(d-last[i]);
        }
        ll maxscr=sum;
        ll idx=0;
        repn(i,26){
            ll a=sum+c[i]*(d-last[i])+s[d][i];
            if(a>maxscr){
                maxscr=a;
                idx=i;
            }
        }
        ans[d]=idx;
        last[idx]=d;
    }

    repn(i,D) cout<<ans[i]<<endl;
    
    return;
}

// 貪欲　少し先も含めて評価
// 104,188,475
void solve2(){
    vector<ll> ans(D+1);
    ll score=-LINF;
    rep(k,366){
        vector<ll> ans_tmp(D+1);
        vector<ll> last(26+1,0);
        ll score_tmp=0;
        repn(d,D){
            ll sum=0;
            ll dd=min(365,d+k);
            repn(i,26){
                //sum-=c[i]*(d-last[i]);
                sum-=c[i]*((dd-last[i])*(dd-last[i]+1)-(d-last[i]-1)*(d-last[i]))/2;
            }
            ll maxscr=-LINF;
            ll idx=0;
            repn(i,26){
                ll a=sum;
                a+=c[i]*((dd-last[i])*(dd-last[i]+1)-(d-last[i]-1)*(d-last[i]))/2;
                a+=s[d][i];
                a-=c[i]*k*(k+1)/2;
                if(a>maxscr){
                    maxscr=a;
                    idx=i;
                }
            }
            ans_tmp[d]=idx;
            last[idx]=d;
            score_tmp+=s[d][idx];
            repn(i,26) score_tmp-=c[i]*(d-last[i]);
        }
        if(score_tmp>score){
            ans=ans_tmp;
            score=score_tmp;
        }
    }

    repn(i,D) cout<<ans[i]<<endl;
    //cout<<ans.size()<<' '<<score<<endl;
}

ll computeScore(vector<ll> vec){
    vector<ll> last(26+1,0);
    ll score=0;
    repn(d,D){
        score+=s[d][vec[d]];
        last[vec[d]]=d;
        repn(i,26) score-=c[i]*(d-last[i]);
    }
    return score;
}

// 局所探索　１点をランダムに選びながら反復
// 78,303,110
void solve3(){
    Timer timer;
    timer.start();
    mt19937 mt(SEED);
    uniform_int_distribution<int> rnd_day(1,365);
    uniform_int_distribution<int> rnd_type(1,26);

    // 初期解をランダムに構成
    vector<ll> ans(D+1);
    repn(d,D) ans[d]=rnd_type(mt);

    ll score=computeScore(ans);

    // day日目に開催するコンテストをタイプtypeに変更してスコア計算
    while(timer.getTime()<1980){
        ll day=rnd_day(mt);
        ll type=rnd_type(mt);
        ll old_day=ans[day];
        ans[day]=type;
        ll scr=computeScore(ans);
        if(scr>score) score=scr;
        else ans[day]=old_day;
    }

    repn(i,D) cout<<ans[i]<<endl;
}

// 局所探索　一点変更＋二点スワップ
// 112,605,135
void solve4(){
    Timer timer;
    timer.start();
    mt19937 mt(SEED);

    // 初期解をランダムに構成
    vector<ll> ans(D+1);
    repn(d,D) ans[d]=mt()%26+1;

    ll score=computeScore(ans);

    //int cnt=0;
    while(timer.getTime()<1975){
        //cnt++;
        // 50%で一点変更
        // 50%で二点スワップ
        if(mt()%2){
            ll day=mt()%365+1;
            ll type=mt()%26+1;
            ll old_day=ans[day];
            ans[day]=type;
            ll scr=computeScore(ans);
            if(scr>score) score=scr;
            else ans[day]=old_day;
        }else{
            ll day1=mt()%365+1;
            ll day2=max(0LL,min(365LL,(ll)(day1+mt()%32-16)));
            if(day2>=0) day2++;
            swap(ans[day1],ans[day2]);
            ll scr=computeScore(ans);
            if(scr>score) score=scr;
            else swap(ans[day1],ans[day2]);
        }
    }

    repn(i,D) cout<<ans[i]<<endl;
    //cout<<cnt<<endl;
}

int main(){
    input();
    //solve1();
    //solve2();
    //solve3();
    solve4();
}