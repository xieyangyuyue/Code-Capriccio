#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int fib(int N) {
		if (N <= 1) return N;
		vector<int> dp(N + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
//			int sum = dp[0] + dp[1];
//			dp[0] = dp[1];
//			dp[1] = sum;
		}
		printDpArray(dp); // 打印 dp 数组
		return dp[1];
	}
	int fib1(int N) {
		if (N < 2) return N;
		return fib(N - 1) + fib(N - 2);
	}

	// 打印 dp 数组的函数
	void printDpArray(const vector<int>& dp) {
		cout << "DP Array: ";
		int size = dp.size();
		for (int i = 0; i < size; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
	}
};

// 主函数，用于测试 Solution 类的 fib 方法以及打印 dp 数组
int main() {
	Solution solution;
	int N = 50; // 你可以更改这个值来计算不同项的斐波那契数
	int result = solution.fib(N);
	cout << "Fibonacci number at position " << N << " is " << result << endl;
	return 0;
}

