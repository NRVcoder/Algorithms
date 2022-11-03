#include<iostream>
#include<vector>
using namespace std;
int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int s = n + 1;
	vector<vector<int>> vec(s, vector<int> (s));
	vector<int> a(s);
	vector<int> b(s);
	vector<int> a1;
	vector<int> b1;
	a[0] = 0;
	b[0] = 0;
	vec[0][0] = 0;
	for (size_t i = 1; i < s; i++){
		cin >> a[i];
		vec[0][i] = 0;
	}
	for (size_t i = 1; i < s; i++) {
		cin >> b[i];
		vec[i][0] = 0;
	}
	for (size_t i = 1; i < s; i++) {
		for (size_t j = 1; j < s; j++) {
			if (a[i] == b[j]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			else {
				vec[i][j] = Max(vec[i - 1][j], vec[i][j - 1]);
			}
		}
	}

	int i = n;
	int j = n;
	while (j != 0 && i != 0 && vec[i][j] != 0 && vec[j][i] != 0) {
		if (a[i] == b[j]) {
			a1.push_back(i);
			b1.push_back(j);
			--i;
			--j;
		}
		else if(vec[i][j] == vec[i - 1][j]) {
			--i;
		}
		else if (vec[i][j] == vec[i][j - 1]) {
			--j;
		}
	}
	
	cout << vec[n][n] << endl;
	for (int i = a1.size() - 1; i >= 0; --i) {
		cout << a1[i] - 1 << " ";
	}
	cout << endl;
	for (int i = b1.size() - 1; i >= 0; i--) {
		cout << b1[i] - 1 << " ";
	}
}