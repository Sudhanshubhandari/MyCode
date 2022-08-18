#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "hii";
}
// class node {
// public:
// 	int data;
// 	node*left;
// 	node*right;
// 	node(int d) {
// 		data = d;
// 		node*left = NULL;
// 		node * right = NULL;
// 	}
// };
// void print(node * root) {
// 	if (root == NULL) {
// 		return ;
// 	}
// 	cout << root->data << " ";

// 	print(root->left);


// 	print(root->right);


// }

// node* buildtree() {
// 	int d;
// 	cin >> d;
// 	if (d == -1) {
// 		return NULL;
// 	}
// 	node*n = new node(d);

// 	n->left = buildtree();
// 	n->right = buildtree();
// 	return n;

// }

// node*findmin(node*root) {
// 	while (root->left != NULL) {
// 		root = root->left;
// 	}
// 	return root;

// }
// node* deleteNode(node* root, int k)
// {

// 	if (root->data < k) {
// 		root->right = deleteNode(root->right, k);
// 	}
// 	else if (root->data > k) {
// 		root->left = deleteNode(root->left, k);
// 	}
// 	else {
// 		if (root->left == NULL and root->right == NULL) {
// 			delete root;
// 			root = NULL;
// 		}
// 		else if (root->left == NULL) {
// 			node*temp = root;
// 			root = root->right;
// 			delete temp;
// 		}
// 		else if (root->right == NULL) {
// 			node*temp = root;
// 			root = root->left;
// 			delete temp;
// 		}
// 		else {
// 			node*temp = findmin(root->right);
// 			root->data = temp->data;
// 			root->right = deleteNode(root->right, temp->data);

// 		}
// 	}
// 	return root;
// }



// int main() {
// 	node*root = buildtree();
// 	deleteNode(root, 10);
// 	print(root);

// }
