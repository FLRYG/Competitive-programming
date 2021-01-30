#include<iostream>
using namespace std;

struct mint{
    int x;
    mint(int a=0):x(a){}
    operator int(){ return x; }
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a){ x+=a.x; return *this; }
    mint& operator-=(const mint a){ x-=a.x; return *this; }
    mint& operator*=(const mint a){ x*=a.x; return *this; }
    mint& operator/=(const mint a){
        int tmp=x/a.x;
        if(x%a.x<0) tmp-=sign(a.x);
        x=tmp;
        return *this;
    }
    mint& operator%=(const mint a){
        int tmp=x%a.x;
        if(tmp<0) tmp+=abs(a.x);
        x=tmp;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint operator/(const mint a) const { return mint(*this) /= a;}
    mint operator%(const mint a) const { return mint(*this) %= a;}
    bool operator==(const mint a) const { return x==a.x?1:0; }
    bool operator!=(const mint a) const { return x!=a.x?1:0; }
    bool operator< (const mint a) const { return x<a.x ?1:0; }
    bool operator<=(const mint a) const { return x<=a.x?1:0; }
    bool operator> (const mint a) const { return x>a.x ?1:0; }
    bool operator>=(const mint a) const { return x>=a.x?1:0; }
    bool operator==(const int a) const { return x==a?1:0; }
    bool operator!=(const int a) const { return x!=a?1:0; }
    bool operator< (const int a) const { return x<a ?1:0; }
    bool operator<=(const int a) const { return x<=a?1:0; }
    bool operator> (const int a) const { return x>a ?1:0; }
    bool operator>=(const int a) const { return x>=a?1:0; }
    static int sign(int a){ return a>0?1:a<0?-1:0; }
    static int abs(int a){ return a>0?a:-a; }
    friend istream& operator>>(istream& is, mint& a) { is >> a.x; return is;}
    friend ostream& operator<<(ostream& os, const mint& a) { os << a.x; return os;}
};