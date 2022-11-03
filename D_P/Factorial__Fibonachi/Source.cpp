#include<iostream>
#include<vector>
using namespace std;
long long Fact(int n) {
	if (n == 0) {
		return 1;
	}
	return Fact(n - 1) * n;
}
long long Fibonachi(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return Fibonachi(n - 1) + Fibonachi(n - 2);
}
long long FibonachiMem(int n, vector<long long>& mem) {
	if (mem[n] == -1) {
		mem[n] = FibonachiMem(n - 1, mem) + FibonachiMem(n - 2, mem);
	}
	return mem[n];
}
int main() {
	int n;
	cin >> n;
	/*vector<long long> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	cout << fact[n];*/
	/*vector<long long> fib(n + 2);
	fib[0] = 0;
	fib[1] = 1;
	for (size_t i = 2; i < n + 2; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cout << fib[n + 1] << endl;*/
	vector<long long> mem(n + 2, -1);
	mem[0] = 0;
	mem[1] = 1;
	cout << FibonachiMem(n + 1);
}