#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> Merge(vector<int> a, vector<int> b) {
	vector<int> vec;
	vector<int>::iterator ita;
	vector<int>::iterator itb;
	ita = a.begin();
	itb = b.begin();
	while(vec.size() != a.size() + b.size()) {
		if (*ita < *itb) {
			vec.push_back(*ita);
				ita++;
				if (ita == a.end()) {
					while (itb != b.end()) {
						vec.push_back(*itb);
						itb++;
					}
					return vec;
				}
		}
		if(*ita >= *itb) {
			vec.push_back(*itb);
			itb++;
			if (itb == b.end()) {
				while (ita != a.end()) {
					vec.push_back(*ita);
					ita++;
				}
				return vec;
			}
		}		
	}
	return vec;
}

void MergeSort(vector<int>& vec, int l, int r) {
	int mid = (l + r) / 2;
	vector<int> a;
	vector<int> b;
	for (int i = l; i < mid; ++i) {
		a[i] = vec[i];
	}
	for (int i = mid; i < r; ++i) {
		b[i] = vec[i];
	}
	MergeSort(a, l, mid);
	MergeSort(b, mid, r);
	if (a.size() == b.size() == 1) {
		Merge(a, b);
	}

}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++){
		cin >> a[i];
	}
	MergeSort(a, 0, n);
	
	for (size_t i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}