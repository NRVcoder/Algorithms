#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int Min(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) {
			return c;
		}
		else {
			return b;
		}
	}
	else if(a <= c) {
		return a;
	}
	else {
		return c;
	}
}
int Comp(char a, char b) {
	if (a == b) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int del;
	fin >> del;
	int ins;
	fin >> ins;
	int repl;
	fin >> repl;
	string a;
	fin >> a;
	string b;
	fin >> b;
	int m = b.size() + 1;
	int n = a.size() + 1;
	vector<vector<int>> vec(n, vector<int>(m));
	vec[0][0] = 0;
	for (int i = 1; i < n; ++i) {
		vec[i][0] = i * del;
	}
	for (int i = 1; i < m; ++i) {
		vec[0][i] = i * ins;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			vec[i][j] = Min(vec[i - 1][j] + del, vec[i][j - 1] + ins,
				vec[i - 1][j - 1] + Comp(a[i - 1], b[j - 1]) * repl);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

	fout << vec[n - 1][m - 1];
	fout.close();
	return 0;
}