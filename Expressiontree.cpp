#include<bits/stdc++.h>
using namespace std;
class node {
public:
	string data;
	node*left;
	node*right;
	node(string d) {
		data = d;
		node*left = NULL;
		node * right = NULL;
	}
};
node* buildtree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	node*n = new node("+");
	node*n1 = new node("5");
	node*n2 = new node("6");
	n->left = n1;
	n->right = n2;


	n->left = buildtree();
	n->right = buildtree();
	return n;

}
bool okay(string key) {
	if (key == "+" or key == "-" or key == "*" or key == "/") {
		return true;
	}
	return false;
}
int evalTree(node* root) {
	if (root == NULL) {
		return 0;
	}
	if (!okay(root->data)) {
		return stoi(root->data);

	}
	if (root->data == "+") return evalTree(root->left) + evalTree(root->right);
	if (root->data == "-") return evalTree(root->left) - evalTree(root->right);
	if (root->data == "*") return evalTree(root->left) * evalTree(root->right);
	if (root->data == "/") return evalTree(root->left) / evalTree(root->right);
}
int main() {
	node*root = buildtree();
	cout << evalTree(root);
}


