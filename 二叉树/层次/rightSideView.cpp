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
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (i == (size - 1)) result.push_back(node->val); // 将每一层的最后元素放入result数组中
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};;

int main() {
	// 创建一个测试二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = nullptr;
	root->left->right = new TreeNode(5);
	root->right->left = nullptr;
	root->right->right = new TreeNode(4);

	Solution solution;
vector<int>views= solution.rightSideView(root);

	// 输出结果
	for (const auto value : views) {
			std::cout << value << " ";
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

