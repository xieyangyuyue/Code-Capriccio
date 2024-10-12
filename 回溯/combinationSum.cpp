#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	// 存储所有找到的组合
	vector<vector<int>> result;
	// 当前正在构建的组合路径
	vector<int> path;
	
	// 回溯函数
	void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
		// 如果当前组合的和等于目标值，存储这个组合
		if (sum == target) {
			result.push_back(path);
			return; // 找到组合后返回
		}
		
		// 遍历候选数字，从 startIndex 开始
		for (int i = startIndex; i < (int)candidates.size() && sum + candidates[i] <= target; i++) {
			sum += candidates[i]; // 将当前数字加入当前组合的和
			path.push_back(candidates[i]); // 将当前数字加入路径
			
			// 递归调用，继续选择下一个数字（允许重复使用同一数字）
			backtracking(candidates, target, sum, i); 
			
			// 回溯：从路径中移除最后一个数字，并从当前和中减去该数字
			sum -= candidates[i];
			path.pop_back();
		}
	}
public:
	// 主函数，输入候选数组和目标值
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		result.clear(); // 清空结果集
		path.clear();   // 清空当前路径
		sort(candidates.begin(), candidates.end()); // 对候选数组进行排序，以便优化剪枝
		backtracking(candidates, target, 0, 0); // 从第一个元素开始回溯
		return result; // 返回找到的组合
	}
};

int main() {
	Solution solution; // 创建解决方案对象
	vector<int> candidates = {2, 3, 6, 7}; // 候选数字
	int target = 7; // 目标和
	vector<vector<int>> combinations = solution.combinationSum(candidates, target); // 调用函数获取组合
	
	// 打印所有组合
	for (const auto& combo : combinations) {
		for (int num : combo) {
			cout << num << " "; // 输出组合中的每个数字
		}
		cout << endl; // 每找到一个组合换行
	}
	
	return 0; // 程序结束
}

