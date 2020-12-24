#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
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

int N=100;
int H=20, W=20;
int x[100];
int y[100];
int num[20][20];

void input(){
    rep(i,H) rep(j,W) num[i][j]=-1;
    rep(i,N){
        cin>>x[i]>>y[i];
        num[x[i]][y[i]]=i;
    }
}

// 貪欲
string solve1(int xs, int ys){
    string ans;
    rep(k,N){
        int i,j;
        if(k==0){
            i=x[k]-xs;
            j=y[k]-ys;
        }else{
            i=x[k]-x[k-1];
            j=y[k]-y[k-1];
        }
        if(i>0) rep(l,i) ans+='D';
        else rep(l,-i) ans+='U';
        if(j>0) rep(l,j) ans+='R';
        else rep(l,-j) ans+='L';
        ans+='I';
    }
    return ans;
}

// 右下に全て集めてから貪欲
string solve2(){
    string ans;
    stack<int> stk;
    int u=0, v=0;

    // 上半分のカードを拾い集める
    while(true){
        if(u==10 && v==0) break;
        if(num[u][v]!=-1){
            ans+="I";
            stk.push(num[u][v]);
            x[num[u][v]]=-1;
            y[num[u][v]]=-1;
            num[u][v]=-1;
        }
        if(u%2==0){
            if(v<W-1){
                v++;
                ans+="R";
            }else{
                u++;
                ans+="D";
            }
        }else{
            if(0<v){
                v--;
                ans+="L";
            }else{
                u++;
                ans+="D";
            }
        }
    }

    // 左下のカードを拾い集める
    while(true){
        if(u==10 && v==10) break;
        if(num[u][v]!=-1){
            ans+="I";
            stk.push(num[u][v]);
            x[num[u][v]]=-1;
            y[num[u][v]]=-1;
            num[u][v]=-1;
        }
        if(v%2==0){
            if(u<H-1){
                u++;
                ans+="D";
            }else{
                v++;
                ans+="R";
            }
        }else{
            if(10<u){
                u--;
                ans+="U";
            }else{
                v++;
                ans+="R";
            }
        }
    }

    // 右下にカードを置いていく
    while(true){
        if(num[u][v]==-1){
            ans+="O";
            int val=stk.top(); stk.pop();
            x[val]=u;
            y[val]=v;
            num[u][v]=val;
        }
        if(stk.empty()) break;
        if(u%2==0){
            if(v<W-1){
                v++;
                ans+="R";
            }else{
                u++;
                ans+="D";
            }
        }else{
            if(10<v){
                v--;
                ans+="L";
            }else{
                u++;
                ans+="D";
            }
        }
    }

    // 順番に拾い集める
    ans+=solve1(u,v);

    return ans;
}

// 右下に全て集めてから貪欲
// 収集を効率よく行う
string solve3(){
    vector<int> fsth(H,W-1);
    vector<int> endh(H,0);
    vector<int> fstv(W,H-1);
    vector<int> endv(W,10);
    rep(i,H){
        rep(j,W){
            if(num[i][W-j-1]!=-1) fsth[i]=W-j-1; 
            if(num[i][j]!=-1) endh[i]=j; 
        }
    }
    rep(j,W/2){
        rep(i,H-10){
            if(num[H-i-1][j]!=-1) fstv[j]=H-i-1; 
            if(num[i+10][j]!=-1) endv[j]=i+10; 
        }
    }
    fsth[9]=0;
    fstv[9]=10;

    // cout<<"Horizon"<<endl;
    // rep(i,H/2) cout<<i<<": "<<fsth[i]<<' '<<endh[i]<<endl;
    // cout<<"Vertical"<<endl;
    // rep(j,W/2) cout<<j<<": "<<fstv[j]<<' '<<endv[j]<<endl;

    string ans;
    stack<int> stk;
    int u=0, v=0;

    // 上半分のカードを拾い集める
    while(true){
        if(u==10 && v==0) break;
        if(num[u][v]!=-1){
            ans+="I";
            stk.push(num[u][v]);
            x[num[u][v]]=-1;
            y[num[u][v]]=-1;
            num[u][v]=-1;
        }
        if(u%2==0){
            if(v<max(endh[u],endh[u+1])){
                v++;
                ans+="R";
            }else{
                u++;
                ans+="D";
            }
        }else{
            if(v>min(fsth[u],fsth[u+1])){
                v--;
                ans+="L";
            }else{
                u++;
                ans+="D";
            }
        }
    }

    // 左下のカードを拾い集める
    while(true){
        if(u==10 && v==10) break;
        if(num[u][v]!=-1){
            ans+="I";
            stk.push(num[u][v]);
            x[num[u][v]]=-1;
            y[num[u][v]]=-1;
            num[u][v]=-1;
        }
        if(v%2==0){
            if(u<max(endv[v],endv[v+1])){
                u++;
                ans+="D";
            }else{
                v++;
                ans+="R";
            }
        }else{
            if(u>min(fstv[v],fstv[v+1])){
                u--;
                ans+="U";
            }else{
                v++;
                ans+="R";
            }
        }
    }

    // 右下にカードを置いていく
    while(true){
        if(num[u][v]==-1){
            ans+="O";
            int val=stk.top(); stk.pop();
            x[val]=u;
            y[val]=v;
            num[u][v]=val;
        }
        if(stk.empty()) break;
        if(u%2==0){
            if(v<W-1){
                v++;
                ans+="R";
            }else{
                u++;
                ans+="D";
            }
        }else{
            if(10<v){
                v--;
                ans+="L";
            }else{
                u++;
                ans+="D";
            }
        }
    }

    // 順番に拾い集める
    ans+=solve1(u,v);

    return ans;
}

string solve04(){
    
}

int main(){
    input();

    // cout<<"  ";
    // rep(i,W) cout<<i%10<<' '; cout<<endl;
    // rep(i,H){
    //     cout<<i%10<<' ';
    //     rep(j,W){
    //         cout<<((num[i][j]!=-1)?'o':'.')<<' ';
    //     }
    //     cout<<endl;
    // }

    // cout<<solve1(0,0)<<endl;
    // cout<<solve2()<<endl;
    // cout<<solve2().size()<<endl;
    cout<<solve3()<<endl;
    // cout<<solve3().size()<<endl;

    return 0;
}