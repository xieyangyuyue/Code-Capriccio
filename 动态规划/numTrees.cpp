#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		int leftTree,rightTree;
		dp[0] = 1; // 空树也是一种情况，所以 dp[0] = 1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				leftTree=dp[j-1];
				rightTree=dp[i-j];
				dp[i] += leftTree * rightTree;
			}
		}
		// 打印 dp 数组
		cout << "DP Array: ";
		for (int i = 0; i <= n; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
		return dp[n];
	}
};

// 主函数，用于测试 Solution 类的 numTrees 方法
int main() {
	Solution solution;
	int n = 5; // 你可以更改这个值来测试不同的节点数
	int result = solution.numTrees(n);
	cout << "The number of unique BSTs with " << n << " nodes is: " << result << endl;
	return 0;
}

