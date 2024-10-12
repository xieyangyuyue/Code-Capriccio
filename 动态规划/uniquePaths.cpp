#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) dp[i][0] = 1;
		for (int j = 0; j < n; j++) dp[0][j] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printDp(dp); // 打印 dp 数组
		return dp[m - 1][n - 1];
	}
	
	// 打印 dp 数组的函数
	void printDp(const vector<vector<int>>& dp) {
		cout << "DP Array:" << endl;
		for (const auto& row : dp) {
			for (int val : row) {
				cout << val << "\t";
			}
			cout << endl;
		}
	}
};

// 主函数，用于测试 Solution 类的 uniquePaths 方法
int main() {
	Solution solution;
	int m = 3; // 网格的行数
	int n = 7; // 网格的列数
	int result = solution.uniquePaths(m, n);
	cout << "Number of unique paths from top-left to bottom-right in a " << m << "x" << n << " grid is: " << result << endl;
	return 0;
}

