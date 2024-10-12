#include <iostream>
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
	// 先序遍历二叉树
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}

	// 递归函数，用于先序遍历
	void traversal(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		vec.push_back(cur->val);    // 访问根节点
		traversal(cur->left, vec);  // 遍历左子树
		traversal(cur->right, vec); // 遍历右子树
	}
};

int main() {
	// 创建一个测试二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	Solution solution;
	vector<int> preorder = solution.preorderTraversal(root);

	// 输出结果
	for (int value : preorder) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	// 清理内存
	delete root->left->right; // 先释放右子节点
	delete root->left->left; // 再释放左子节点
	delete root->right; // 释放右子节点
	delete root->left; // 释放左子节点
	delete root; // 最后释放根节点

	return 0;
}

