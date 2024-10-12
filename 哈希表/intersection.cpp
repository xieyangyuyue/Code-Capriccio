#include <iostream>
#include <vector>
#include <unordered_set>

//set 哈希表
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
	std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
	for (int num : nums2) {
		// 发现nums2的元素 在nums_set里又出现过
		if (nums_set.find(num) != nums_set.end()) {
			result_set.insert(num);
		}
	}
	return std::vector<int>(result_set.begin(), result_set.end());
}

//数组 哈希表
std::vector<int> intersection1(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
	int hash[1005] = {0}; // 默认数值为0
	for (int num : nums1) { // nums1中出现的字母在hash数组中做记录
		hash[num] = 1;
	}
	for (int num : nums2) { // nums2中出现话，result记录
		if (hash[num] == 1) {
			result_set.insert(num);
		}
	}
	return std::vector<int>(result_set.begin(), result_set.end());
}

int main() {
	std::vector<int> nums1 = {1, 2, 3, 4, 5};
	std::vector<int> nums2 = {4, 5, 6, 7, 8};
	std::vector<int> result = intersection(nums1, nums2);
	std::cout << "Intersection: ";
	for (int num : result) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}

