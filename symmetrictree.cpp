
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
bool isSymmetric(node* root) {
	queue<node*>q1;
	queue<node*>q2;
	if (root == NULL || root->left == NULL && root->right == NULL) {
		return true;
	}
	if ( root->left == NULL || root->right == NULL) {
		return false;;
	}
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty() and !q2.empty()) {
		node*c1 = q1.front();
		q1.pop();
		node*c2 = q2.front();
		q2.pop();
		if (q1.empty() and !q2.empty()) {
			return false;
		}
		if (!q1.empty() and q2.empty()) {
			return false;
		}
		if (c1->left == NULL and c2->right != NULL) {
			return false;
		}
		if (c1->left != NULL and c2->right == NULL) {
			return false;
		}

		if (c1->data != c2->data)
			return false;
		if (c1->left) {
			q1.push(c1->left);
		}
		if (c1->right) {
			q1.push(c1->right);
		}

		if (c2->left) {
			q1.push(c2->left);
		}
		if (c2->right) {
			q1.push(c2->right);
		}

	}
	if (q1.empty() and q2.empty()) {
		return true;
	}
	return false;
}
int main() {
	node*root = buildtree();
	cout << isSymmetric(root);
}