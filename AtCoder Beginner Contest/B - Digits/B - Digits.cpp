#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int digit = 0;
	do
	{
		N = N / K;
		digit++;
	} while (N != 0);

	cout << digit;
}
