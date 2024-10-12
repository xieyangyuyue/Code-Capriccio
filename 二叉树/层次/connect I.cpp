#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	
	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
	
	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
	
	Node(int _val, Node* _left, Node* _right, Node* _next)
	: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root) return nullptr;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Node* node = que.front();
				que.pop();
				if (i < size - 1) {
					node->next = que.front();
				} else {
					node->next = nullptr;
				}
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return root;
	}
};

// 层序遍历打印二叉树
void printTree(Node* root) {
	if (!root) return;
	queue<Node*> que;
	que.push(root);
	while (!que.empty()) {
		int levelSize = que.size(); // 当前层的节点数量
		for (int i = 0; i < levelSize; i++) {
			Node* node = que.front();
			que.pop();
			cout << node->val;
			if (node->next) {
				cout << " -> " << node->next->val;
			} else {
				cout << " -> #";
			}
			if (i < levelSize - 1) cout << " | "; // 分隔同一层的节点
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		cout << endl; // 每层结束后换行
	}
}

// 释放二叉树节点的辅助函数
void freeTree(Node* root) {
	if (!root) return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

int main() {
	// 创建一个完美二叉树
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	// 连接二叉树
	Solution solution;
	solution.connect(root);
	
	// 打印二叉树
	printTree(root);
	
	// 释放二叉树
	freeTree(root);
	
	return 0;
}

