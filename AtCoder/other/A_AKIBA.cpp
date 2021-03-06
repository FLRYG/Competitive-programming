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

int N;
string S;

int main(){
    cin>>S;
    
    bool flag=false;
    flag|=S=="KIHBR";
    flag|=S=="KIHABR";
    flag|=S=="KIHBAR";
    flag|=S=="KIHBRA";
    flag|=S=="KIHABAR";
    flag|=S=="KIHBARA";
    flag|=S=="KIHABRA";
    flag|=S=="KIHABARA";
    flag|=S=="AKIHBR";
    flag|=S=="AKIHABR";
    flag|=S=="AKIHBAR";
    flag|=S=="AKIHBRA";
    flag|=S=="AKIHABAR";
    flag|=S=="AKIHBARA";
    flag|=S=="AKIHABRA";
    flag|=S=="AKIHABARA";
    if(flag){
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;

    return 0;
}