#include <iostream>
#include <vector>
#include <algorithm> // 用于 sort 函数

class Solution {
public:
	// 找出数组中所有满足 a + b + c = 0 的三元组
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> result;
		std::sort(nums.begin(), nums.end());

		// 找出a + b + c = 0
		// a = nums[i], b = nums[left], c = nums[right]
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			// 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
			if (nums[i] > 0) {
				return result;
			}
			// 正确去重a方法
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left) {
				int threeSum = nums[i] + nums[left] + nums[right] ;
				if (threeSum > 0)
					right--;
				else if (threeSum < 0)
					left++;
				else {

					result.push_back(std::vector<int> {nums[i], nums[left], nums[right]});
					// 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;

					// 找到答案时，双指针同时收缩
					right--;
					left++;
				}
			}
		}
		return result;
	}
};

int main() {
	// 创建一个测试数组
	std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
	Solution solution;
	std::vector<std::vector<int>> result = solution.threeSum(nums);

	// 输出结果
	std::cout << "Three Sum results:" << std::endl;
	for (const auto& triplet : result) {
		for (int num : triplet) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

