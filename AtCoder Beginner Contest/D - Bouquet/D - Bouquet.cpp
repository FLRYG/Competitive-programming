#include <iostream>

int conbinationX(int n,int r)
{
	if (r > n / 2) {
		r = n - r;
	}
	int a=1;
	int b=1;
	for (int i = 0; i < r; i++) {
		a *= (n - i);
		b *= (1 + i);
	}
	return a;
}

int conbinationY(int n, int r)
{
	if (r > n / 2) {
		r = n - r;
	}
	int a = 1;
	int b = 1;
	for (int i = 0; i < r; i++) {
		a *= (n - i);
		b *= (1 + i);
	}
	return b;
}

int powMod(int a, int n, int p)
{
	int res = 1;
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		int x=powMod(a, n / 2, p);
		return (x * x) % p;
	}
	return a * powMod(a, n - 1, p);
}

int main()
{
	int n, a, b;
	std::cin >> n >> a >> b;

	int main, A, B;
	main = powMod(2, n, 1000000007);
	A = conbinationX(n, a) * powMod(conbinationY(n, a), 1000000005, 1000000007);
	B = conbinationX(n, b) * powMod(conbinationY(n, b), 1000000005, 1000000007);

	int res;
	res = main - 1 - A - B;

	std::cout << res;
}
