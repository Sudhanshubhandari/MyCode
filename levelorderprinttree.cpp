
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
vector<int> printKthLevel(node* root, int k) {

	vector<int>v;
	queue<node*>q;
	q.push(root);
	int flag = 0;
	int level = 0;

	while (!q.empty()) {
		int size = q.size();

		while (size--) {


			node*current = q.front();
			q.pop();

			if (level == k) {
				flag = 1;
				v.push_back(current->data);
			}
			else {
				if (current->left) {
					q.push(current->left);
				}
				if (current->right) {
					q.push(current->right);
				}
			}
		}

		level++;


		if (flag == 1) {
			break;
		}
	}

	return v;
}
void levelorderprint(node*root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node*temp = q.front();
		if (temp == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}

		}
	}
	return;
}

// node* levelorderbuild() {
// 	int d;
// 	cin >> d;
// 	node*root = new node(d);
// 	queue<node*>q;
// 	q.push(root);
// 	while (!q.empty()) {
// 		node*current = q.front();
// 		q.pop();
// 		int c1, c2;
// 		if (c1 != 0) {
// 			current->left = new node(c1);
// 			q.push(current->left);
// 		}
// 		if (c2 != 0) {
// 			current->right = new node(c2);
// 			q.push(current->right);
// 		}
// 	}
// 	return root;

// }

// int sumBT(Node* root)
// {
// 	queue<node*>q;
// 	int size = q.size();
// 	helper(root, size);

// }
int main() {
	int k = 1;

	node*root = buildtree();
	vector<int>h = printKthLevel(root, k);
	for (int l = 0; l < h.size(); l++) {
		cout << h[l] << " ";
	}

}