#include<iostream>  
#include<vector> 
#include<cmath>
#include<algorithm>  
#include<fstream>  
using namespace std;
struct Node {
    int value;
    int amountL;
    int amountR;
    Node* right = nullptr;
    Node* left = nullptr;
};
/*void Insert(Node*& root, int x) {
    if (root == 0) {
        root = new Node;
        root->value = x;
        root->left = nullptr;
        root->right = nullptr;
        root->amountL = 0;
        root->amountR = 0;
        return;
    }
    if (x < root->value) {
        Insert(root->left, x);
    }
    if (x > root->value) {
        Insert(root->right, x);
    }
}*/
void Insert(Node*& root, int x) {
    if (root == 0) {
        root = new Node;
        root->value = x;
        root->left = nullptr;
        root->right = nullptr;
        root->amountL = 0;
        root->amountR = 0;
        return;
    }
    if (x < root->value) {
        Insert(root->left, x);
    }
    if (x > root->value) {
        Insert(root->right, x);
    }
}
void CountingUnderTrees(Node* root) {

    if (root->left != nullptr) {
        CountingUnderTrees(root->left);
    }
    if (root->left != nullptr) {
        root->amountL = (root->left->amountL + root->left->amountR) + 1;
    }
    if (root->right != nullptr) {
        CountingUnderTrees(root->right);
    }
    if (root->right != nullptr) {
        root->amountR = (root->right->amountL + root->right->amountR) + 1;
    }
}
void Find(Node* root, vector<int>& vec, int& count) {
    if (abs(root->amountL - root->amountR) == 2) {
        vec.push_back(root->value);
        count++;
    }
    if (root->left != nullptr) {
        Find(root->left, vec, count);
    }
    if (root->right != nullptr) {
        Find(root->right, vec, count);
    }
}
void Remove(Node*& root, int x) {

    Node* current = root;
    Node* prev = nullptr;
    if (root->left == nullptr && root->right == nullptr) {
        root = nullptr;
        delete root;
        return;
    }
    while ((current != nullptr) && (current->value != x)) {
        if (x < current->value) {
            prev = current;
            current = current->left;
            if (current == nullptr) {
                return;
            }
        }
        if (x > current->value) {
            prev = current;
            current = current->right;
            if (current == nullptr) {
                return;
            }
        }
    }



    if ((current->left == nullptr) && (current->right == nullptr)) {//  LEAF
        if (prev->right == current) {
            prev->right = nullptr;
            delete current;
        }
        if (prev->left == current) {
            prev->left = nullptr;
            delete current;
        }
        return;
    }

    if ((current->left != nullptr) && (current->right == nullptr)) {

        if (prev == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
            return;
        }
        if (prev->left == current) {
            prev->left = current->left;
            delete current;
            return;
        }
        if (prev->right == current) {
            prev->right = current->left;
            delete current;
            return;
        }
    }

    if ((current->right != nullptr) && (current->left == nullptr)) {
        if (prev == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
            return;
        }
        if (prev->left == current) {
            prev->left = current->right;
            delete current;
            return;
        }
        if (prev->right == current) {
            prev->right = current->right;
            delete current;
            return;
        }
    }

    if ((current->left != nullptr) && (current->right != nullptr)) { //Hard
        Node* find = current->left;
        while (find->right != nullptr) {
            find = find->right;
        }

        current->value = find->value;

        Remove(current->left, find->value);

        return;
    }

}

void DLB(Node* root, ofstream& fout) {
    fout << root->value << endl;
    if (root->left != nullptr) {
        DLB(root->left, fout);
    }
    if (root->right != nullptr) {
        DLB(root->right, fout);
    }
}
int main() {
    Node* root = nullptr;
    int n;
    vector<int> vec;
    int count = 0;
    ifstream fin("tst.in");
    ofstream fout("tst.out");
    while (fin >> n) {
        Insert(root, n);
    }
    CountingUnderTrees(root);
    Find(root, vec, count);
    if (count % 2 == 0) {
        DLB(root, fout);
        fout.close();
        return 0;
    }
    sort(vec.begin(), vec.end());
    Remove(root, vec[vec.size() / 2]);
    DLB(root, fout);
    fout.close();
    return 0;
}