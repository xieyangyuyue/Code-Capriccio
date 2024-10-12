#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
	TreeNode* invertTreeRecursionPre(TreeNode* root) {
		if (root == NULL) return root;
		invertTreeRecursionPre(root->left);
		invertTreeRecursionPre(root->right);
		swap(root->left, root->right);
		return root;
	}
};

// Helper function to print in-order traversal of the tree
void printInOrder(TreeNode* node) {
	if (node == nullptr) return;
	printInOrder(node->left);
	cout << node->val << " ";
	printInOrder(node->right);
}

// Helper function to delete the tree and free memory
void deleteTree(TreeNode* node) {
	if (node == nullptr) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

int main() {
	// Create a sample binary tree:
	//      4
	//     / \
	//    2   7
	//   / \ / \
	//  1  3 6  9
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	// Create a Solution object
	Solution solution;

	// Invert the tree
	cout << "Original tree in-order traversal: ";
	printInOrder(root);
	cout << endl;

	TreeNode* invertedRoot = solution.invertTreeRecursionPre(root);

	// Print the inverted tree
	cout << "Inverted tree in-order traversal: ";
	printInOrder(invertedRoot);
	cout << endl;

	// Clean up memory
	deleteTree(invertedRoot);

	return 0;
}

