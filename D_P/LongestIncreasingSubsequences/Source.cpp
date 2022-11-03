#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int LowerBound(vector<int>& vec, int value, int l, int r) {
	int mid = (r + l) / 2;
	if (r == l) {
		return r;
	}
	if (value > vec[mid]) {
		mid++;
		return LowerBound(vec, value, mid, r);
	}
	else {
		return LowerBound(vec, value, l, mid);
	}
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		fin >> vec[i];
	}
	vector<int> sub(n + 1, 1200000);
	int a = 0;
	for (int i = 0; i < n; ++i) {
		a = LowerBound(sub, vec[i], 0, i);
		if (sub[a] > vec[i]) {
			sub[a] = vec[i];
		}
	}
	int count = 0;
	while(sub[count] != 1200000) {
		count++;
	}
	/*for (int i = 0; i < n; ++i) {
		cout << sub[i] << endl;
	}*/
	fout << count;
	fout.close();
	return 0;
}