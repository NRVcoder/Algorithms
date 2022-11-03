#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int Min1(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int Min(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) {
			return c;
		}
		else {
			return b;
		}
	}
	else if (a <= c) {
		return a;
	}
	else {
		return c;
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	int m;
	fin >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fin >> mat[i][j];
		}
	}
	if (m == 1) {
		for (int i = 1; i < n; ++i) {
			mat[i][0] += mat[i - 1][0];
		}
		fout << mat[n - 1][m - 1];
		fout.close();
		return 0;
	}
	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < m; ++i) {
		vec[0][i] = mat[0][i];
	}
	
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j != 0 && j != m - 1) {
				vec[i][j] = Min(vec[i - 1][j + 1], vec[i - 1][j],
					vec[i - 1][j - 1]) + mat[i][j];
			}
			else if(j == m - 1) {
				vec[i][j] = Min1(vec[i - 1][j - 1], vec[i - 1][j]) + mat[i][j];
			}
			else if (j == 0) {
				vec[i][j] = Min1(vec[i - 1][j + 1], vec[i - 1][j]) + mat[i][j];
			}
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}*/

	int min = vec[n - 1][0];
	for (int i = 1; i < m; ++i) {	
		if (vec[n - 1][i] < min) {
			min = vec[n - 1][i];
		}
	}
	fout << min;
	fout.close();
	return 0;
}