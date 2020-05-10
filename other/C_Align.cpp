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

int N;
int A[100000];
deque<int> deq;

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    int l=1, r=N-1;
    int cnt=0;
    deq.push_back(A[0]);
    repn(i,N-1){
        if(r){
            if(cnt=0){
                deq.pop_front(A[])
            }
        }
    }
}