#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
struct A {
	int value = 0;
	int index = 0;
};
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	if (n == 0) {
		fout << 0;
		fout.close();
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		fin >> v[i];
	}
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) {
			v.erase(v.begin());
			i--;
			count++;
		}
	}
	if (count == n) {
		fout << 0;
		fout.close();
		return 0;
	}
	while (count != 0) {
		v.push_back(0);
		count--;
	}
	
	
	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		vec[i][i] = 1;
	}
	/*for (int i = 0; i < n - 1; ++i) {
		if (v[i + 1] % v[i] == 0) {
			vec[i][i + 1] = 2;
		}
		else {
			vec[i][i + 1] = 1;
		}
	}*/
	A a;
	for (int i = 0; i < n; ++i) {
		a.value = v[i];
		a.index = i;
		for (int j = 1 + i; j + i < n; ++j) {
			if (v[j] % a.value == 0) {
				vec[i][j] = vec[i][a.index] + 1;
				a.value = v[j];
				a.index = j;
			}
			else {
				vec[i][j] = vec[i][a.index];
			}
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}*/

	int max = -2000000000;
	for (int i = 0; i < n; ++i) {
		if (vec[i][n - 1] > max) {
			max = vec[i][n - 1];
		}
	}
	fout << max;
	fout.close();
	return 0;
}