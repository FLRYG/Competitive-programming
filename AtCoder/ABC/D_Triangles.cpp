#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N;
int L[2000];

int first,second;

int f(int begin,int end){
    if(end-begin<=1){
        if(first-second<L[begin]){
            return begin;
        }
        return end;
    }

    int c=(begin+end)/2;
    if(first-second<L[c]){
        f(begin,c);
    }else{
        f(c,end);
    }
}

int main(){
    cin>>N;
    rep(i,N) cin>>L[i];

    sort(L,L+N);

    //rep(i,N) cout<<L[i]<<' ';
    //cout<<endl;

    int ans=0;
    for(int i=N-1;i>=2;i--){
        for(int j=i-1;j>=1;j--){
            first=L[i];
            second=L[j];
            int s=f(0,j);
            //cout<<"i="<<i<<",j="<<j<<",s="<<s<<endl;
            ans+=j-s;
        }
    }

    cout<<ans<<endl;
}