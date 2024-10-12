#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	// 翻转二叉树
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return root;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			TreeNode* node = que.front();
			que.pop();
			swap(node->left, node->right); // 交换左右子节点
			if (node->left) que.push(node->left); // 将左子节点加入队列
			if (node->right) que.push(node->right); // 将右子节点加入队列
		}
		return root;
	}
};

// 层次遍历打印二叉树
void printLevelOrder(TreeNode* root) {
	if (root == NULL) return;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		int levelSize = que.size(); // 当前层的节点数量
		for (int i = 0; i < levelSize; i++) {
			TreeNode* node = que.front();
			que.pop();
			cout << node->val << " "; // 打印节点值
			if (node->left) que.push(node->left); // 将左子节点加入队列
			if (node->right) que.push(node->right); // 将右子节点加入队列
		}
		cout << endl; // 每层打印完毕换行
	}
}

// 释放二叉树内存
void deleteTree(TreeNode* root) {
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	
	// 创建Solution对象
	Solution solution;
	
	// 打印原始二叉树层次遍历结果
	cout << "原始二叉树层次遍历结果：" << endl;
	printLevelOrder(root);
	
	// 翻转二叉树
	solution.invertTree(root);
	
	// 打印翻转后的二叉树层次遍历结果
	cout << "翻转后二叉树层次遍历结果：" << endl;
	printLevelOrder(root);
	
	// 释放二叉树内存
	deleteTree(root);
	
	return 0;
}

