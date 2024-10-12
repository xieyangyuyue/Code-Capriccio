#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 在有序数组中搜索目标值
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
		while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
			int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
			//因为左闭右闭，middle已经使用过 ，不可再包含
			if (nums[middle] > target) {
				right = middle - 1; // target 在左区间，所以[left, middle - 1]
			} else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，所以[middle + 1, right]
			} else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}

	// 版本二
public:
	int search1(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
		while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
			int middle = left + ((right - left) >> 1);
			// //因为左闭右开，middle未使用过 ，可再包含
			if (nums[middle] > target) {
				right = middle; // target 在左区间，在[left, middle)中
			} else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，在[middle + 1, right)中
			} else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}

};

int main() {
	Solution solution;
	std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int target = 4;

	int result = solution.search1(nums, target);
	if (result != -1) {
		std::cout << "Element found at index: " << result << std::endl;
	} else {
		std::cout << "Element not found in the array." << std::endl;
	}
	return 0;
}
