#include <iostream>
#include <queue>
#include <vector>

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
	// 计算二叉树的最大深度
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left)
					que.push(node->left);
				if (node->right)
					que.push(node->right);
			}
		}
		return depth;
	}
};

int main() {
	//创建一个测试二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = nullptr;
	root->left->right = nullptr;
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution solution;
	int depth = solution.maxDepth(root);

	// 输出结果
	std::cout << "Maximum depth of the binary tree is: " << depth << std::endl;
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

