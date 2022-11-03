#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class LongDigit {
	vector<int> vec;
public:
	vector<int> Sum(vector<int> a, vector<int> b) {
		int length;
		if (a.size() > b.size()) {
			length = a.size() + 1;
		}
		else {
			length = b.size() + 1;
		}
		vector<int> sum(length);
		for (size_t i = 0; i < length - 1; i++){
			sum[i] = (a[i] + b[i]) % 10;
			sum[i + 1] += (a[i] + b[i]) / 10;
		} 
		if (sum[length - 1] == 0) {
			length--;
		}
		return sum;
	}


};
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int K;
	cin >> K;
	vector<vector<long long>> vec(N + 1, vector<long long> (K + 1));
	for (size_t i = 0; i <= K; i++){
		vec[i][i] = 1;
	}
	for (size_t i = 0; i <= N; i++) {
		vec[i][0] = 1;
	}
	/*long long p = 1e9 + 7;
	for (size_t i = 2; i <= N; i++){
		for (size_t j = 1; (j <= i) && (j <= K); j++) {
			vec[i][j] = ((vec[i - 1][j - 1] % p) + (vec[i - 1][j] % p)) % p;
		}
	}
	
	cout << vec[N][K];*/
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; (j < i) && (j < K); j++) {
			vec[i][j] = 2;
		}
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; (j < i) && (j < K); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}