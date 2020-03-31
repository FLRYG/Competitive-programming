#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static vector<int> P={2};
template<class T>
T next_prime(T x){
    int size=P.size();
    
    if(x<P[size-1]){
        int begin=0,end=size;
        while(end-begin>1){
            int c=(begin+end)/2;
            if(x<P[c]){
                end=c;
            }else{
                begin=c;
            }
        }
        return P[begin];
    }

    T res=P[size-1];
    while(true){
        res++;
        bool prime=true;
        for(int i=0;i<size;i++){
            if(P[i]<=sqrt((double)res)){
                if(res%P[i]==0){
                    prime=false;
                    break;
                }
            }else{
                break;
            }
        }

        if(prime){
            P.push_back(res);
            size++;
            if(res>x){
                break;
            }
        }
    }

    return res;
}

template<class T>
bool prime(T x){
    if(x==next_prime(x-1)) return true;
    return false;
}

int main(){
    int prime=1;
    for(int i=0;i<100;i++){
        prime=next_prime(prime);
        cout<<prime<<endl;
    }
}