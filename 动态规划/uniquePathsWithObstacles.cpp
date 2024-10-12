#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //如果在起点或终点出现了障碍，直接返回0
			return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
		for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printDp(dp); // 打印 dp 数组
		return dp[m - 1][n - 1];
	}
	
	int uniquePathsWithObstaclestest(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
			return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if ((i == 0 || j == 0) && obstacleGrid[i][j] == 0) {
					dp[i][j] = 1;
				} else if (obstacleGrid[i][j] == 1)
					continue;
				else
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
				cout << val << " ";
			}
			cout << endl;
		}
	}
};

// 主函数，用于测试 Solution 类的 uniquePathsWithObstacles 方法
int main() {
	Solution solution;
	vector<vector<int>> obstacleGrid = {
		{0,0},
		{1,1},
		{0,0}
	}; // 你可以更改这个数组来测试不同的障碍物配置
	int result = solution.uniquePathsWithObstaclestest(obstacleGrid);
	cout << "Number of unique paths with obstacles is: " << result << endl;
	return 0;
}

