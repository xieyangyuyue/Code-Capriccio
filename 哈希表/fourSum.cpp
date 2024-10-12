#include<iostream>
#include <vector>
#include <algorithm> // 用于sort函数
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result; // 存储最终结果的二维向量
		sort(nums.begin(), nums.end()); // 对数组进行排序，为后续剪枝和去重做准备
		for (int k = 0; k < (int)nums.size(); k++) {
			// 剪枝处理：如果当前数字大于目标和且非负，则后续不可能有解，直接退出循环
			if (nums[k] > target && nums[k] >= 0) {
				break;
			}
			// 对nums[k]去重：如果当前数字与前一个数字相同，则跳过
			if (k > 0 && nums[k] == nums[k - 1]) {
				continue;
			}
			for (int i = k + 1; i <(int) nums.size(); i++) {
				// 2级剪枝处理：如果nums[k]和nums[i]的和大于目标和且非负，则后续不可能有解，直接退出内层循环
				if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
					break;
				}
				// 对nums[i]去重：如果当前数字与前一个数字相同，则跳过
				if (i > k + 1 && nums[i] == nums[i - 1]) {
					continue;
				}
				int left = i + 1; // 左指针
				int right = nums.size() - 1; // 右指针
				while (right > left) {
					// 判断四数之和是否大于目标和，防止溢出
					if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
						right--; // 大于目标和，右指针左移
					}
					// 判断四数之和是否小于目标和，防止溢出
					else if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) {
						left++; // 小于目标和，左指针右移
					} else {
						// 找到一组解，加入结果集
						result.push_back(vector<int> {nums[k], nums[i], nums[left], nums[right]});
						// 对nums[left]和nums[right]去重
						while (right > left && nums[right] == nums[right - 1]) right--;
						while (right > left && nums[left] == nums[left + 1]) left++;
						// 找到答案时，双指针同时收缩
						right--;
						left++;
					}
				}
			}
		}
		return result; // 返回最终结果
	}
};

int main() {
	Solution solution;
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	int target = 0;

	vector<vector<int>> result = solution.fourSum(nums, target);

	// 打印结果
	for (const auto& quadruplet : result) {
		cout << "[";
		for (size_t i = 0; i < quadruplet.size(); ++i) {
			cout << quadruplet[i];
			if (i < quadruplet.size() - 1) cout << ", ";
		}
		cout << "]" << endl;
	}

	return 0;
}

