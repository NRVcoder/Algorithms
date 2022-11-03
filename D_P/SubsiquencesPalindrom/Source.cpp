#include<iostream>
#include<vector>
#include<string>
#include<fstream>
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
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s;
	fin >> s;
	int n = s.size();
	string copy;
	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		vec[i][i] = 1;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[1 + i]) {
			vec[i][i + 1] = 2;
		}
		else  {
			vec[i][i + 1] = 1;
		}
	}

	for (size_t i = 2; i < n; i++) {
		for (size_t j = 0; j < n - i; j++) {
			if (s[j] == s[i + j]) {
				vec[j][i + j] = vec[j + 1][j + i - 1] + 2;
			}
			if (s[j] != s[i + j]) {
				vec[j][i + j] = Max(vec[j + 1][j + i], vec[j][j + i - 1]);
			}
		}
	}

	int i = 0;
	int j = n - 1;
	while (j >= i) {
		if (s[i] == s[j]) {
			copy.push_back(s[i]);
			++i;
			--j;
		}
		else if (vec[i][j] == vec[i + 1][j]) {
			++i;
		}
		else if (vec[i][j] == vec[i][j - 1]) {
			--j;
		}
	}
	
	fout << vec[0][n - 1] << endl;
	for (int i = 0; i < vec[0][n - 1]; ++i) {
		if (i < copy.size()) {
			fout << copy[i];
		}
		else {
			fout << copy[vec[0][n - 1] - i - 1];
		}
	}
	fout.close();
	return 0;
}