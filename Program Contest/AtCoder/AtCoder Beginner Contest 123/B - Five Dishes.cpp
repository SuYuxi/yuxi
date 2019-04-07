#include <iostream>
#include <vector>
using namespace std;
int maxtime(int x)
{
	return (x + 9) / 10 * 10;
}

int remtime(int x)
{
	return maxtime(x) - x;
}

int main()
{
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	int sum = maxtime(A) + maxtime(B) + maxtime(C) + maxtime(D) +maxtime(E);
	sum -= max(remtime(A), max(remtime(B), max(remtime(C), max(remtime(D), remtime(E)))));
	cout << sum << endl;
	return 0;
}

