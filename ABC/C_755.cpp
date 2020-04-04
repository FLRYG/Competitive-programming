#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int powi(int x,int n){if(n==0)return 1;return x*powi(x,n-1);}

int N;
const int table[3]={3,5,7};

bool _753(int k){
    int digit=log10(k)+1;
    bool c3,c5,c7;
        rep(i,digit){
            if(k%10==3) c3=true;
            if(k%10==5) c5=true;
            if(k%10==7) c7=true;
            k/=10;
        }
    return c3&&c5&&c7;
}

int def(int x,int m){
    int res=0;
    rep(i,3){
        int k=10*x+table[i];
        cout<<
        //int digit=log10(k)+1;
        if(k<=m){
            /*bool c3,c5,c7;
            rep(i,digit){
                if(k%10==3) c3=true;
                if(k%10==5) c5=true;
                if(k%10==7) c7=true;
                k/=10;
            }*/
            if(_753(k)) res++;
            res+=def(k,m);
        }
    }
    return res;
}

int main(){
    cin>>N;
    
    int ans=def(0,N);

    cout<<ans<<endl;
}