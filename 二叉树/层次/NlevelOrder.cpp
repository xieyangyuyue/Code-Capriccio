#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 定义多叉树节点
class Node {
public:
	int val;
	vector<Node*> children;
	
	Node() {}
	
	Node(int _val) {
		val = _val;
	}
	
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	// 多叉树的层序遍历
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> que;
		if (root != NULL)
			que.push(root);
		vector<vector<int>> res;
		while (!que.empty()) {
			int n = que.size();
			vector<int> temp;
			while (n--) {
				Node* node = que.front();
				que.pop();
				temp.push_back(node->val);
				int childsize=node->children.size();
				for (int i = 0; i < childsize; i++) {
					if (node->children[i])
						que.push(node->children[i]);
				}
			}
			res.push_back(temp);
		}
		return res;
	}
};

int main() {
	// 创建一个测试多叉树
	Node* root = new Node(1);
	root->children.push_back(new Node(3));
	root->children.push_back(new Node(2));
	root->children.push_back(new Node(4));
	root->children[0]->children.push_back(new Node(5));
	root->children[0]->children.push_back(new Node(6));
	
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
	delete root->children[0]->children[0];
	delete root->children[0]->children[1];
	delete root->children[0];
	delete root->children[1];
	delete root->children[2];
	delete root;
	
	return 0;
}

