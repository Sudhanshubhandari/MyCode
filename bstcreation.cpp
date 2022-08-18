
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int key;
	node*left;
	node*right;
	node(int key) {
		this->key = key;
		left = right = NULL;
	}
};
// bool search(node*root, int g) {
// 	if (root == NULL) {
// 		return false;
// 	}
// 	if (g == root->key) {
// 		return true;

// 	}
// 	if (g < root->key) {
// 		root->left = search(root->left, g);
// 	}
// 	if (g > root->key) {
// 		root->right = search(root->right, g);
// 	}


// }


node * insert(node*root, int key) {
	if (root == NULL) {
		return new node(key);
	}
	if (key < root->key) {
		root->left = insert(root->left, key);
	}
	if (key > root->key) {
		root->right = insert(root->right, key);
	}
	return root;
}
void print(node * root) {
	if (root == NULL) {
		return ;
	}
	print(root->left);
	cout << root->key << " ";
	print(root->right);

}



node*findmin(node*root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;

}
node*remove(node*root, int key) {
	if (root == NULL) {
		return NULL;
	}
	else if (key < root->key) {
		root->left = remove(root->left, key);
	}
	else if (key > root->key) {
		root->right = remove(root->right, key);
	}
	// when the current nodes matches with the key
	else
	{	if (root->left == NULL && root->right == NULL ) {
			delete root;
			root = NULL;

		}
		else if (root->left == NULL) {
			node*temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node*temp = root;
			root = root->left;
			delete temp;
		}
		else {
			node*temp = findmin(root->right);
			root->key = temp->key;
			root->right = remove(root->right, temp->key);

		}
	}
	return root;
}


int main() {
	node*root = NULL;
	int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for (int x : a) {
		root = insert(root, x);
	}
	root = remove(root, 10);
	print(root);
	// search(root, 10);
}