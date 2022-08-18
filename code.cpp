#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node * links[26];
	int cntEndWith = 0;
	int cntPrefix = 0;
	bool flag = false;

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	Node * get(char ch) {
		return links[ch - 'a'];
	}
	void put(char ch, Node * node) {
		links[ch - 'a'] = node;
	}
	void increaseEnd() {
		cntEndWith++;
	}
	void increasePrefix() {
		cntPrefix++;
	}
	void deleteEnd() {
		cntEndWith--;
	}
	void reducePrefix() {
		cntPrefix--;
	}
	int getEnd() {
		return cntEndWith;
	}
	int getPrefix() {
		return cntPrefix;
	}
	bool isend() {
		return flag;;
	}
	bool setend() {
		flag = true;
	}

};
class Trie {
private:
	Node * root;

public:

	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */

	// INSERTION

	void insert(string word) {
		Node * node = root;
		for (int i = 0; i < word.length(); i++) {
			if (!node -> containsKey(word[i])) {
				node -> put(word[i], new Node());
			}
			node = node -> get(word[i]);
			node -> increasePrefix();
		}
		node -> increaseEnd();
		node->setend();
	}


	// SEARCHING

	bool search(string word) {
		Node*node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}

		return node->isend();
	}

	// STARTS WITH (PREFIX)

	bool start(string word) {
		Node*node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return true;
	}


	int countWordsEqualTo(string &word)
	{
		Node *node = root;
		for (int i = 0; i < word.length(); i++)
		{
			if (node->containsKey(word[i]))
			{
				node = node->get(word[i]);
			}
			else
			{
				return 0;
			}
		}
		return node->getEnd();
	}


	int countWordsStartingWith(string & word) {
		Node * node = root;
		for (int i = 0; i < word.length(); i++) {
			if (node -> containsKey(word[i])) {
				node = node -> get(word[i]);
			} else {
				return 0;
			}
		}
		return node -> getPrefix();
	}

	void erase(string & word) {
		Node * node = root;
		for (int i = 0; i < word.length(); i++) {
			if (node -> containsKey(word[i])) {
				node = node -> get(word[i]);
				node -> reducePrefix();
			} else {
				return;
			}
		}
		node -> deleteEnd();
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


#endif
	Trie T;
	T.insert("apple");
	T.insert("apple");
	T.insert("apps");
	T.insert("apps");
	string word1 = "apps";
	cout << "Count Words Equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
	string word2 = "abc";
	cout << "Count Words Equal to " << word2 << " " << T.countWordsEqualTo(word2) << endl;
	string word3 = "ap";
	cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3)
	     << endl;
	string word4 = "appl";
	cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4)
	     << endl;
	T.erase(word1);
	cout << "Count Words equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
	string word5 = "apple";
	cout << word5 << T.search(word5);

	return 0;
}





