#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// 定义二叉树节点
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			// 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
	}
};

int main() {
	// 创建一个测试二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = nullptr;
	root->left->right = nullptr;
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution solution;
	vector<vector<int> >levels = solution.levelOrder(root);

	// 输出结果
	for (const auto&level : levels) {
		for (int value : level) {
			std::cout << value << " ";
		}
		cout << endl;
	}


	// 清理内存
	delete root->right->right;
	delete root->right->left;
	delete root->left->right; // 先释放右子节点
	delete root->left->left; // 再释放左子节点
	delete root->right; // 释放右子节点
	delete root->left; // 释放左子节点
	delete root; // 最后释放根节点

	return 0;
}

