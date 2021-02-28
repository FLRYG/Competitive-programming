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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll A[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    ll z=0, a=0, b=0;
    rep(i,N){
        if(A[i]==0) z++;
        if(A[i]>0) a++;
        if(A[i]<0) b++;
    }

    ll neg=a*b;
    ll zer=z*(a+b)+z*(z-1)/2;
    ll pos=a*(a-1)/2+b*(b-1)/2;

    ll ok=0, ng=LINF;
    while(ng-ok>1){
        ll m=(ok+ng)/2;
        
    }

    if(neg<K && K<=neg+zer){
        cout<<0<<endl;
    }else if(K<=neg){

    }else{

    }
    
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const long MAX=1'000'000'000;

// int main(){
//     int N,K;
//     cin>>N>>K;
//     vector<long> A(N);
//     int cminus=0,czero=0,cplus=0;
//     for(int i=0;i<N;i++){
//         cin>>A[i];
//         if(A[i]<0) cminus++;
//         else if(A[i]>0) cplus++;
//         else czero++;
//     }
//     sort(A.begin,A.end);
//     int minus,zero,plus;
//     minus=cminus*cplus;
//     zero=czero*(N-czero)+czero*(czero-1)/2;
//     plus=(cplus*(cplus-1)+cminus*(cminus-1))/2;

//     long inf=-MAX*MAX,sup=MAX*MAX;
//     long x;
//     if(K<=minus){
//         sup=0;
//         x=(inf+sup)/2;
//         for(int i=0;i<N;i++){
//             while(A[i]*A[N-i]<x){
                
//             }
//         }
//     }else if(K<=minus+zero){
//         cout<<0;
//     }else{
// }

/*int main(){
    int N,K;
    long* A;

    cin>>N>>K;
    A=new long[N];

    int cminus=0,czero=0,cplus=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0) cminus++;
        else if(A[i]>0) cplus++;
        else czero++;
    }
    
    cout<<cminus<<' '<<czero<<' '<<cplus<<'\n';

    int minus,zero,plus;
    minus=cminus*cplus;
    zero=czero*(N-czero)+czero*(czero-1)/2;
    plus=(cplus*(cplus-1)+cminus*(cminus-1))/2;

    cout<<minus<<' '<<zero<<' '<<plus<<'\n';

    long* X;
    if(K<=minus){
        X=new long[minus];
        int count=0;
        for(int i=0;i<N;i++){
            if(!(A[i]<0)){
                continue;
            }
            for(int j=0;j<N;j++){
                if(A[j]>0){
                    X[count++]=A[i]+A[j];
                }
            }
        }
        cout<<X[K-1];
        delete[] X;
    }else if(K<=minus+zero){

    }else{

    }

    

    delete[] A;

}*/

/*int main(){
    long int N;
    int K;
    long int* A;
    list<long int> ls;
    cin>>N>>K;
    A=new long int[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
        for(int j=i-1;j>=0;j--){
            ls.push_front(A[i]*A[j]);
        }
    }

    ls.sort();

    cout<<*std::next(ls.begin(),K-1)<<endl;
    delete[] A;
}*/