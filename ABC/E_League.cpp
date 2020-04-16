#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;


int main(){

}

/*
int N;
queue<int> A[1000];
bool energy[1000];

//O(N^3) TLE
int main(){
    cin>>N;
    rep(i,N){
        rep(j,N-1){
            int x;
            cin>>x;
            A[i].push(x);
        }
    }

    int ans=0;
    int sum=N*(N-1)/2;
    while(sum>0){
        int psum=sum;
        fill(energy,energy+N,true);
        ans++;
        //cout<<"day"<<ans<<endl;
        for(int i=0;i<N;i++){
            if(!A[i].empty()){
                int x=A[i].front();
                if(A[x-1].front()-1==i && energy[i] && energy[x-1]){
                    //cout<<' '<<i+1<<"vs"<<x<<endl;
                    A[i].pop();
                    A[x-1].pop();
                    energy[i]=false;
                    energy[x-1]=false;
                    sum--;
                }
            }
        }
        if(psum==sum) break;
    }

    if(!sum){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
}*/