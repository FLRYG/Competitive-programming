#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin,A.end);
}

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