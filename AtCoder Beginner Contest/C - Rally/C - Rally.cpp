#include <iostream>

int main()
{
	int N;
	int* X;
	std::cin >> N;
	X = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> X[i];
	}

	double mean=0;
	for (int i = 0; i < N; i++)
	{
		mean += X[i];
	}
	mean = mean / (double)N;

	int P;
	if (mean - (int)mean >= 0.5) {
		P = (int)mean + 1;
	}
	else {
		P = (int)mean;
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (X[i] - P) * (X[i] - P);
	}

	std::cout << sum;

	delete[] X;
}
