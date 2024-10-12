#include <iostream>
#include <vector>
#include <algorithm> // 用于 min 函数

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int size=cost.size();
		vector<int> dp(size + 1);
		dp[0] = 0; // 默认第一步都是不花费体力的
		dp[1] = 0;
		for (int i = 2; i <= size; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		printArray(dp); // 打印 dp 数组
		return dp[size];
	}
	
	// 打印数组的函数
	void printArray(const vector<int>& arr) {
		cout << "Array: ";
		int size=arr.size();
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

// 主函数，用于测试 Solution 类的 minCostClimbingStairs 方法
int main() {
	Solution solution;
	vector<int> cost = {1,100,1,1,1,100,1,1,100,1}; // 你可以更改这个数组来测试不同的楼梯成本
	int result = solution.minCostClimbingStairs(cost);
	cout << "Minimum cost to reach the top is: " << result << endl;
	return 0;
}


