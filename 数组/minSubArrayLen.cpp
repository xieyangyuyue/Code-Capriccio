#include <iostream>
#include <vector>
#include<math.h>
#include <climits> // 用于 INT_MAX
/*暴力解法*/
int minSubArrayLen1(int s, std::vector<int>& nums) {
	int n = nums.size();
	int result = INT32_MAX; // 最终的结果
	int sum = 0; // 子序列的数值之和
	int subLength = 0; // 子序列的长度
	for (int i = 0; i < n; i++) { // 设置子序列起点为i
		sum = 0;
		for (int j = i; j < n; j++) { // 设置子序列终止位置为j
			sum += nums[j];
			if (sum >= s) { // 一旦发现子序列和超过了s，更新result
				subLength = j - i + 1; // 取子序列的长度
				result = result < subLength ? result : subLength;
				break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
			}
		}
	}
	// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
	return result == INT32_MAX ? 0 : result;
}

/*滑动窗口*/
int minSubArrayLen(int s, std::vector<int>& nums) {
	int n = nums.size();
	int result = INT32_MAX;
	int sum = 0; // 滑动窗口数值之和
	int i = 0; // 滑动窗口起始位置
	int subLength = 0; // 滑动窗口的长度
	for (int j = 0; j < n; j++) {
		sum += nums[j];
		// 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
		while (sum >= s) {
			subLength = j - i + 1;
			result = std::min(result, subLength) ;// 取子序列的长度
			sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
		}
	}
	// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
	return result == INT32_MAX ? 0 : result;
}
int main() {
	std::vector<int> nums = {2, 3, 1, 2, 4, 3};
	int target = 7;
	int result = minSubArrayLen(target, nums);
	std::cout << "The minimum length of a subarray is: " << result << std::endl;
	return 0;
}

