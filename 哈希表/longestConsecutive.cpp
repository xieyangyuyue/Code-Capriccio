#include<iostream>
#include <unordered_set>
#include <vector>
#include <algorithm> // 用于max函数

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> num_set; // 使用哈希集合存储数组中的元素，以便快速查找
		
		// 将数组中的所有元素插入到哈希集合中
		for (const int& num : nums) {
			num_set.insert(num);
		}
		
		int longestStreak = 0; // 记录最长的连续序列长度
		
		// 遍历哈希集合中的每个元素
		for (const int& num : num_set) {
			// 如果当前元素的前一个元素不在集合中，说明当前元素可能是连续序列的起点
			if (!num_set.count(num - 1)) {
				int currentNum = num; // 当前连续序列的起点
				int currentStreak = 1; // 当前连续序列的长度
				
				// 查找当前连续序列的下一个元素，直到找不到为止
				while (num_set.count(currentNum + 1)) {
					currentNum += 1; // 移动到下一个元素
					currentStreak += 1; // 增加当前连续序列的长度
				}
				
				// 更新最长的连续序列长度
				longestStreak = max(longestStreak, currentStreak);
			}
		}
		
		return longestStreak; // 返回最长的连续序列长度
	}
};
int main() {
	Solution solution;
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	int result = solution.longestConsecutive(nums);
	cout << "The length of the longest consecutive sequence is: " << result << endl;
	return 0;
}

