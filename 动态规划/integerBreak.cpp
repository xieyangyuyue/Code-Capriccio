#include <iostream>
#include <vector>
#include <algorithm> // 用于 max 函数

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {
				dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
			}
		}
		// 打印 dp 数组
		cout << "DP Array: ";
		for (int i = 2; i <= n; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
		return dp[n];
	}


};

// 主函数，用于测试 Solution 类的 integerBreak 方法
int main() {
	Solution solution;
	int n = 12; // 你可以更改这个值来测试不同的整数
	int result = solution.integerBreak(n);
	cout << "The maximum product of the integer break of " << n << " is: " << result << endl;
	return 0;
}

