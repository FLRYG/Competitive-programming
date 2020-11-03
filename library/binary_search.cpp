#include <iostream>
using namespace std;

int N;
int a[100];
int x;

void binary_search(){
    int l=-1;
    int r=N;
    while(r-l>1) {
        int mid=l+(r-l)/2;
        if (a[mid]>=x) r=mid;
        else l=mid;
    }
}