#include<iostream>
#include<vector>
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
int BinSearch(vector<int>& vec, int value, int l, int r) {
	int mid = (r + l) / 2;
	if (r == l) {
		if (r != vec.size()) {
			if (vec[r] != value) {
				return 0;
			}
			else {
				return 1;
			}
	    }
		return 0;
	}

	if (value > vec[mid]) {
		mid++;
		return BinSearch(vec, value, mid, r);
	}
	else {
		return BinSearch(vec, value, l, mid);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	vector<int> vec(k);
	for (int i = 0; i < k; ++i) {
		cin >> vec[i];
	}
	int n;
	cin >> n;
	vector<int> request(n);
	for (int i = 0; i < n; ++i) {
		cin >> request[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << BinSearch(vec, request[i], 0, vec.size()) << " "
			<< LowerBound(vec, request[i], 0, vec.size()) 
			<< " " << LowerBound(vec, request[i] + 1, 0, vec.size())
			<< endl;
	}
	return 0;
}
