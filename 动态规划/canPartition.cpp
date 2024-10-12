#include <iostream>
#include <vector>
#include <numeric> // 用于accumulate函数，计算数组元素总和

using namespace std;

class Solution {
public:
	// 判断数组是否可以被分割成两个和相等的子集
	bool canPartition(vector<int>& nums) {
		// 计算数组所有元素的总和
		int sum = accumulate(nums.begin(), nums.end(), 0);
		// 如果总和是奇数，无法分割成两个和相等的子集
		if (sum % 2 == 1) return false;
		// 计算目标和，即总和的一半
		int target = sum / 2;
		
		// 初始化动态规划数组，大小为目标和+1，初始值为0
		vector<int> dp(10001, 0);
		/*
		// weight数组的大小 就是物品个数
		for (int i = 1; i < (int)weight.size(); i++) { // 遍历物品
		for (int j = bagweight; j>=weight[i]; j--) { // 遍历背包容量
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		
		}
		}
		*/
		// 遍历数组中的每一个元素
		for (int i = 0; i < (int)nums.size(); i++) {
			// 从目标和开始向下遍历，更新动态规划数组
			for (int j = target; j >= nums[i]; j--) {
				// 更新dp[j]，选择当前元素或不选择当前元素的最大值
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		// 打印动态规划数组
		cout << "Array elements: ";
		for (int j = 0; j <= target; j++) {
			cout << dp[j] << " ";
		}
		cout << endl;
		// 如果dp[target]等于目标和，说明可以分割成两个和相等的子集
		return dp[target] == target;
	}
};

int main() {
	// 创建一个示例数组
	vector<int> nums = {1, 5, 11, 5};
	
	// 创建Solution对象
	Solution solution;
	
	// 调用canPartition函数并打印结果
	bool canPartition = solution.canPartition(nums);
	cout << "Can the array be partitioned into two subsets with equal sum? " << (canPartition ? "Yes" : "No") << endl;
	
	return 0;
}

