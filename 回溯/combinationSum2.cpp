#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int>> result; // 用于存储符合条件的所有组合
	vector<int> path; // 当前正在构建的组合路径

	// 回溯函数，搜索所有可能的组合
	void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
		// 如果当前组合的和等于目标值，则将该组合加入到结果中
		if (sum == target) {
			result.push_back(path);
			return;
		}

		// 遍历候选数组，从startIndex开始
		for (int i = startIndex; i < (int)candidates.size() && sum + candidates[i] <= target; i++) {
			// 跳过重复的元素，确保在同一层中不使用相同的元素
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
				continue; // 跳过重复元素
			}

			// 选择当前元素，更新和与路径
			sum += candidates[i]; // 更新当前和
			path.push_back(candidates[i]); // 将当前元素加入到路径中
			used[i] = true; // 标记当前元素为已使用

			// 递归调用，继续寻找下一个元素
			backtracking(candidates, target, sum, i + 1, used); // 这里是i + 1，保证每个数字只能使用一次

			// 撤销选择，准备尝试下一个元素
			used[i] = false; // 回溯，将当前元素标记为未使用
			sum -= candidates[i]; // 减去当前元素的值，恢复和
			path.pop_back(); // 从路径中移除当前元素
		}
	}

public:
	// 主函数，用于初始化并调用回溯函数
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<bool> used(candidates.size(), false);
		path.clear(); // 清空当前路径
		result.clear(); // 清空结果集合

		// 排序，使相同元素挨在一起以便去重
		sort(candidates.begin(), candidates.end());

		// 开始回溯
		backtracking(candidates, target, 0, 0, used);

		// 返回所有找到的组合
		return result;
	}
};

int main() {
	// 定义候选数组和目标值
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;

	// 创建Solution对象
	Solution sol;

	// 调用组合总和函数，获取所有符合条件的组合
	vector<vector<int>> result = sol.combinationSum2(candidates, target);

	// 输出结果
	cout << "所有不同的组合是：" << endl;
	for (const auto& combination : result) {
		cout << "[ ";
		for (int num : combination) {
			cout << num << " ";
		}
		cout << "]" << endl;
	}

	return 0; // 程序结束
}

