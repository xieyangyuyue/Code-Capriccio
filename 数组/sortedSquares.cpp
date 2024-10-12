#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 对数组中的每个元素进行平方，然后排序后返回
	vector<int> sortedSquares(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int k = right;
		vector<int> result(nums.size(), 0);
		while (left <= right) {
			int numsleft = nums[left] * nums[left];
			int numsright = nums[right] * nums[right];
			if (numsleft < numsright) {
				result[k--] = numsright;
				right--;
			} else {
				result[k--] = numsleft;
				left++;
			}
		}
		return result;
	}
};

int main() {
	// 创建一个测试数组
	vector<int> nums = {-5, -1, 0, 2, 4};
	Solution solution;
	vector<int> result = solution.sortedSquares(nums);

	// 输出结果
	cout << "Sorted squares: ";
	for (int val : result) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

