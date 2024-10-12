#include <iostream>
#include <vector>
#include<stack>
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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();                       // 中
			st.pop();
			result.push_back(node->val);
			if (node->right) st.push(node->right);           // 右（空节点不入栈）
			if (node->left) st.push(node->left);             // 左（空节点不入栈）
		}
		return result;
	}
};

int main() {
	// 创建一个测试二叉树
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);

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

