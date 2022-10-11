//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//long long LowerBound(vector<long long> vec, int l, int r, long long value) {
//	if (l == r) {
//		if (value <= vec[r]) {
//			return r;
//		}
//		else /*if (value > vec[r])*/ {
//			return r + 1;
//		}
//	}
//	int mid = (l + r) / 2;
//	if (value <= vec[mid]) {
//		return LowerBound(vec, l, mid, value);
//	}
//	if (value > vec[mid]) {
//		mid++;
//		return LowerBound(vec, mid, r, value);
//	}
//}
//long long UpperBound(vector<long long> vec, int l, int r, long long value) {
//	return LowerBound(vec, l, r, value + 1);
//}
//int BinarySearch(vector<long long> vec, int left, int right, long long value) {
//	if (left == right) {
//		if (value == vec[right]) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	int mid = (left + right) / 2;
//	if (value <= vec[mid]) {
//		return BinarySearch(vec, left, mid, value);
//	}
//	if (value > vec[mid]) {
//		mid++;
//		return BinarySearch(vec, mid, right, value);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<long long> vec(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> vec[i];
//	}
//	int k;
//	cin >> k;
//	vector<int> request(k);
//	for (long long i = 0; i < k; ++i) {
//		cin >> request[i];
//	}
//	for (int i = 0; i < k; ++i) {
//		cout << BinarySearch(vec, 0, vec.size() - 1, request[i]) << " "
//			<< LowerBound(vec, 0, vec.size() - 1, request[i]) << " " 
//			<< UpperBound(vec, 0, vec.size() - 1, request[i])<< endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//int BinarySearch(vector<int> vec, int value) {
//	int l = 0;
//	int r = vec.size();
//	while (l != r) {
//		int mid = (l + r) / 2;
//		if (vec[mid] == value) {
//			return 1;
//		}
//		if (value > vec[mid]) {
//			l = mid + 1;
//		}
//		else if (value <= vec[mid]) {
//			r = mid;
//		}
//	}
//	return 0;
//}
//int LowerBound(vector<int> vec, int value) {
//	int l = 0;
//	int r = vec.size();
//	while (l != r) {
//		int mid = (l + r) / 2;
//		if (value > vec[mid]) {
//			l = mid + 1;
//		}
//		else if (value <= vec[mid]) {
//			r = mid;
//		}
//	}
//	return l;
//}
//int UpperBound(vector<int> vec, int value) {
//	return LowerBound(vec, value + 1);
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int> vec(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> vec[i];
//	}
//	int k;
//	cin >> k;
//	vector<int> request(k);
//	for (long long i = 0; i < k; ++i) {
//		cin >> request[i];
//	}
//	for (int i = 0; i < k; ++i) {
//		cout << BinarySearch(vec, request[i]) << " "
//			<< LowerBound(vec, request[i]) << " "
//			<< UpperBound(vec, request[i]) << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch_Iter(vector<int> arr, int key)
{
    int left = 0;
    int right = arr.size();

    while (left < right) {

        int mid = (right + left) / 2;

        if (arr[mid] == key) {
            return true;
        }
        if (arr[mid] > key) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return false;
}

int l_searchIndex(vector<int> arr, int x) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
        int k = (l + r) / 2;
        if (x <= arr[k]) {
            r = k;
        }
        else {
            l = k + 1;
        }
    }
    return l;
}

int upper_searchIndex(vector<int> arr, int x) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
        int k = (l + r) / 2;
        if (x < arr[k]) {
            r = k;
        }
        else {
            l = k + 1;
        }
    }
    return l;
}


int main() {
    int size;
    int size_query;
    int x;
    cin >> size;
    vector<int> arr(size);

    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    cin >> size_query;
    for (int i = 0; i < size_query; i++) {
        cin >> x;
        cout << BinarySearch_Iter(arr, x) << " "
            << l_searchIndex(arr, x) << " "
            << upper_searchIndex(arr, x) << endl;
    }
    return 0;
}