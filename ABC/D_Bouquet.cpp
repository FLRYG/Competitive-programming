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

const ll MOD=1'000'000'007;

ll n,a,b;

ll mpow(ll x,ll n){
	if(n==0) return 1;
	if(n%2==1) return x*mpow(x,n-1)%MOD;
	else return mpow(x*x%MOD,n/2)%MOD;
}

ll mfrac(ll n){
	ll res=1;
	for(int i=1;i<=n;i++) res=res*i%MOD;
	return res;
}

ll mcomb(ll n,ll r){
	if(n-r<r) r=n-r;
	ll x=1;
	for(int i=0;i<r;i++) x=x*(n-i)%MOD;
	ll y=mpow(mfrac(r),MOD-2);
	return x*y%MOD;
}

int main(){
	cin>>n>>a>>b;

	cout<<mfrac(13)<<endl;

	ll x=mpow(2,n);
	ll y=mcomb(n,a);
	ll z=mcomb(n,b);
	cout<<x<<" "<<y<<" "<<z<<endl;;

	ll ans=(x-y-z-1)%MOD;
	cout<<ans<<endl;
}

/*long int conbinationX(long int n,long int r)
{
	if (r > n / 2) {
		r = n - r;
	}
	long int X=1;
	for (long int i = 0; i < r; i++) {
		//X *= (n - i);
		X*=n-i;
		X%=divide;
	}
	//std::cout<<X<<'\n';
	return X;
}

long int conbinationY(long int n, long int r)
{
	if (r > n / 2) {
		r = n - r;
	}
	long int Y = 1;
	for (int i = 0; i < r; i++) {
		//Y *= (1 + i);
		Y*=1+i;
		Y%=divide;
	}
	//std::cout<<Y<<'\n';
	return Y;
}

long int powMod(long int a, long int n, long int p)
{
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		long int x=powMod(a, n / 2, p);
		return (x * x) % p;
	}
	return a * powMod(a, n - 1, p);
}

int main()
{
	long int n, a, b;
	std::cin >> n >> a >> b;

	long int res;
	//long long main, A, B;
	res = powMod(2, n, divide);
	res -=1;
	res -= conbinationX(n, a) * powMod(conbinationY(n, a), divide-2, divide)%divide;
	std::cout<<conbinationX(n, a)<<' '<<conbinationY(n, a)<<
	' '<<powMod(conbinationY(n, a), divide-2, divide)<<'\n';
	std::cout<<conbinationX(n, a) * powMod(conbinationY(n, a), divide-2, divide)<<'\n';
	std::cout<<conbinationX(n, a) * powMod(conbinationY(n, a), divide-2, divide)%divide<<'\n';
	res -= conbinationX(n, b) * powMod(conbinationY(n, b), divide-2, divide)%divide;
	std::cout<<conbinationX(n, b)<<' '<<conbinationY(n, b)<<
	' '<<powMod(conbinationY(n, b), divide-2, divide)<<'\n';

	//std::cout<<main<<'\n'<<A<<'\n'<<B<<'\n';

	//res = main - 1 - A - B;

	std::cout << res;
}*/
