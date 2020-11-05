#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int xyh[100][3];

int main(){
    cin>>N;
    rep(i,N) cin>>xyh[i][0]>>xyh[i][1]>>xyh[i][2];

    int ans[3];
    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
            bool first=true;
            int H=1;
            rep(i,N){
                if(xyh[i][2]==0) continue;
                int res=abs(xyh[i][0]-cx)+abs(xyh[i][1]-cy)+xyh[i][2];
                if(first){
                    H=res;
                    first=!first;
                }else{
                    if(!(res==H)) goto a;
                }
            }
            //十分条件///
            rep(i,N){
                if(xyh[i][2]==0 && H-abs(xyh[i][0]-cx)-abs(xyh[i][1]-cy)>0)
                    goto a;
            }
            ////////////
            ans[0]=cx; ans[1]=cy; ans[2]=H;
            goto b;
            a:;
        }
    }
    b:;

    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
}