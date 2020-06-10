#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef pair<double,double> P;

int A,B,C,D,E,F;
vector<int> water, suger;

int main(){
    cin>>A>>B>>C>>D>>E>>F;

    rep(i,F+1){
        rep(j,F+1){
            int w=100*(A*i+B*j);
            int s=C*i+D*j;
            if(w<=F) water.push_back(w);
            if(s<=F) suger.push_back(s);
        }
    }

    int anssum=0, ansS=0;
    double x=0;
    rep(i,water.size()){
        rep(j,suger.size()){
            if(water[i]==0) continue;
            if(suger[j]<=water[i]/100*E && water[i]+suger[j]<=F){
                if(x<=100.0*suger[j]/(double)(water[i]+suger[j])){
                    x=100.0*suger[j]/(double)(water[i]+suger[j]);
                    anssum=water[i]+suger[j];
                    ansS=suger[j];
                }
            }
        }
    }

    cout<<anssum<<' '<<ansS<<endl;
}