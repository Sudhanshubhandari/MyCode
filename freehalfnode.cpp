
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;
	node(int d) {
		data = d;
		node*left = NULL;
		node * right = NULL;
	}
};
void inorder(node*root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node* buildtree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	node*n = new node(d);
	n->left = buildtree();
	n->right = buildtree();
	return n;

}


node*check(node*root) {
	if (root == NULL) {
		return NULL;
	}
	root->left = check(root->left);
	root->right = check(root->right);
	if (root->left == NULL and root->right == NULL) {
		return root;
	}
	if (root->left == NULL) {
		node*temp = root->left;
		free(root);
		return temp;
	}
	if (root->right == NULL) {
		node*temp = root->right;
		free(root);
		return temp;
	}
	return root;

}

// vector<int> removeHalfNodes(node *root)
// {
// 	vector<int>v;
// 	check(root, v);
// 	return v;

// }
int main() {
	node*root = buildtree();
	// vector<int>h = removeHalfNodes(root);
	// for (int i = 0; i < h.size(); i++) {
	// 	cout << h[i] << " ";
	// }
	// check(root);
	inorder(check(root));


}