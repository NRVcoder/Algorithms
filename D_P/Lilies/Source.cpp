#include<iostream>
#include<vector>
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
int MaxFrog(vector<int>& mosquito, int n, vector<int>& vec) {
	if (n == 0) {
		return -999;
	}
	if (vec[n - 1] == -1) {
		vec[n - 1] = (Max(MaxFrog(mosquito, n - 2, vec),
		       MaxFrog(mosquito, n - 3, vec)) + mosquito[n - 1]);
	}
	return vec[n - 1];
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	vector<int> mosquito(n);
	for (size_t i = 0; i < n; i++) {
		fin >> mosquito[i];
	}
	vector<int> vec(n, -1);
	vec[0] = mosquito[0];
	vec[1] = -999999999;
	if (MaxFrog(mosquito, n, vec) < 0) {
		fout << -1;
	}
	else {
		fout << MaxFrog(mosquito, n, vec);
	}
	return 0;
}