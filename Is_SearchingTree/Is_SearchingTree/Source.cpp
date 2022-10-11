#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
struct Tree {
	int value;
	int line = 0;
	char c = 'L';
	int lb = -858993460;
	int rb = 858993460;
};
istream& operator>>(istream& in, Tree& t) {
	in >> t.value >> t.line >> t.c;
	return in;
}
ostream& operator<<(ostream& o, const Tree& t) {
	o << t.value << " " << t.line << " " << t.c << endl;
	return o;
}


void Check(vector<Tree> vec, ofstream& fout) {
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i].c == 'L') {
			vec[i].rb = vec[(vec[i].line - 1)].value;
			vec[i].lb = vec[(vec[i].line - 1)].lb;
			if (vec[i].lb < vec[i].value && vec[i].rb > vec[i].value) {
				
			}
			else {
				fout << "NO";
				return;
			}
		}
		if (vec[i].c == 'R') {
			vec[i].lb = vec[(vec[i].line - 1)].value;
			vec[i].rb = vec[(vec[i].line - 1)].rb;
			if (vec[i].lb <= vec[i].value && vec[i].rb > vec[i].value) {
				
			}
			else {
				fout << "NO";
				return;
			}
		}
	}
	fout << "YES";
}

int main() {
	ifstream fin("bst.in");
	ofstream fout("bst.out");
	int n;
	fin >> n;
	int root;
	fin >> root;
	Tree t;
	t.value = root;
	t.line = 0;
	t.c = ' ';
	vector<Tree> vec;
	vec.push_back(t);
	while (fin >> t) {
		vec.push_back(t);
	}
	
	Check(vec, fout);
	return 0;
}

/*2
1
2 1 R
3 2 R
4 3 R
0 1 L
-2 6 L
- 4 7 L
-3 8 R*/