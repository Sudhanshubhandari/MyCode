#include<bits/stdc++.h>
using namescpace std;

struct Node {
	Node *links[2];

	boolcontainskey(int bit) {
		return links[bit];
	}
	int get(int bit) {
		return links[bit];
	}
	void put(int bit, Node*node) {
		links[bit] = node;
	}

};
class trie {
private:
	Node*root;
public:
	trie() {
		root = new Node();
	}

public:
	void insert(int num) {
		Node*node = root;
		for (int i = 31; i >= 0; i--) {
			int bit = n >> i & 1;
			if (!boolcontainskey[bit]) {
				node->put(bit, new node());
			}
			Node->get(bit);
		}

	}
	int max()
}