#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 定义二叉树节点
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 对二叉树进行层序遍历
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size(); // 当前层节点的数量
			vector<int> vec; // 存储当前层节点的值
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val); // 添加当前节点的值
				if (node->left) que.push(node->left); // 如果左子节点存在，则加入队列
				if (node->right) que.push(node->right); // 如果右子节点存在，则加入队列
			}
			result.push_back(vec); // 将当前层的节点值添加到结果向量中
		}
		return result; // 返回层序遍历的结果
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
	vector<vector<int>> levels = solution.levelOrder(root);

	// 输出结果
	for (const auto& level : levels) {
		for (int value : level) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}

	// 清理内存
	delete root;
	delete root->left;
	delete root->right;
	delete root->left->left;
	delete root->left->right;

	return 0;
}

