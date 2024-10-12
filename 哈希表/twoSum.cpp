#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> map;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		// 遍历当前元素，并在map中寻找是否有匹配的key
		auto iter = map.find(target - nums[i]);
		if (iter != map.end()) {
			return {iter->second, i};
		}
		// 如果没找到匹配对，就把访问过的元素和下标加入到map中
		map.insert(std::pair<int, int>(nums[i], i));
	}
	// 如果没有找到匹配对，返回空vector
	return {};
}

int main() {
	std::vector<int> nums = {2, 8, 11, 15, 7};
	int target = 9;
	std::vector<int> result = twoSum(nums, target);
	std::cout << "The indices are: " << result[0] << " and " << result[1] << std::endl;
	return 0;
}

