#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
struct Matrix {
	int n;
	int m;
};
istream& operator>>(istream& in, Matrix& mat) {
	in >> mat.n >> mat.m;
	return in;
}
ostream& operator<<(ostream& o, const Matrix& mat) {
	o << mat.n << " " << mat.m << endl;
	return o;
}
//int Min(vector<Matrix> vec, int i, int j) {
//	if (j - i == 1) {
//		 return vec[i].n * vec[i].m * vec[j].n;
//	}
//	if (Min(vec, i, j) < Min(vec, i, j)) {
//
//	}
//}
//long long Count(vector<Matrix> vec, int S) {
//	if (S == 1) {
//		return 0;
//	}
//	if (S == 2) {
//		return vec[S - 2].n * vec[S - 2].m * vec[S - 1].n;
//	}
//	//return Min()
//}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int S;
	fin >> S;
	vector<Matrix> matrix(S);
	for (size_t i = 0; i < S; i++){
		fin >> matrix[i];
	}
	vector<vector<int>> vec(S, vector<int> (S) );
	/*for (size_t i = 0; i < S; i++) {
		vec[i][i] = 0;
		if (i != S - 1) {
			vec[i][i + 1] = matrix[i].n * matrix[i].m * matrix[i + 1].m;
		}
	}*/

	for (size_t i = 0; i < S; i++) {
		for (size_t j = 0; j < S - i; j++) {
			if (i == 0) {
				vec[j][j + i] = 0;
			}
			if (i == 1) {
				vec[j][j + i] = matrix[j].n * matrix[j].m * matrix[j + 1].m;
			}
			else {
				int temp;
				for (size_t k = j; k < j + i ; k++) {
					 temp = vec[j][k] + vec[k + 1][i + j] + (matrix[j].n * matrix[k].m * matrix[i + j].m);
					if (vec[j][i + j] >= temp || k == j) {
						vec[j][i + j] = temp;
					}
				}
			}
		}
	}

	/*for (size_t i = 0; i < S; i++) {
		for (size_t j = 0; j < S; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}*/
	fout << vec[0][S - 1];
	fout.close();
	return 0;
}
