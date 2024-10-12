#include <iostream> // 引入输入输出库
#include <vector>   // 引入向量（动态数组）库

using namespace std; // 使用标准命名空间

class Solution {
private:
	vector<vector<int>> result; // 存放结果集，二维向量，保存所有符合条件的组合
	vector<int> path; // 存放当前符合条件的组合

	// backtracking 方法用于回溯搜索
	// targetSum：目标和，也就是题目中的 n。
	// k：题目中要求 k 个数的集合。
	// sum：已经收集的元素的总和，也就是 path 里元素的总和。
	// startIndex：下一层 for 循环搜索的起始位置。
	void backtracking(int targetSum, int k, int sum, int startIndex) {
		if (sum > targetSum) { // 剪枝操作
			return;
		}
		// 如果当前组合的大小已经达到 k
		if ((int)path.size() == k) {
			// 检查这些数字的和是否等于目标和
			if (sum == targetSum) {
				result.push_back(path); // 将符合条件的组合添加到结果集中
			}
			return; // 如果 path.size() == k 但 sum != targetSum 直接返回
		}

		// 从 startIndex 开始遍历数字 1 到 9
		for (int i = startIndex; i <= 9 - (k - (int)path.size()) + 1; i++) { // 剪枝
			sum += i; // 处理：将当前数字加入到和中
			path.push_back(i); // 处理：将当前数字添加到组合中

			// 递归调用，继续寻找下一个数字，i + 1 确保不重复使用相同的数字
			backtracking(targetSum, k, sum, i + 1);

			// 回溯操作：从和中移除当前数字
			sum -= i; // 处理：更新和
			path.pop_back(); // 处理：移除当前数字
		}
	}

public:
	// 主函数：找出所有符合条件的组合
	vector<vector<int>> combinationSum3(int k, int n) {
		result.clear(); // 清空之前的结果集（可以不加，因为 new 对象时会自动清空）
		path.clear();   // 清空当前路径（可以不加，因为 new 对象时会自动清空）

		// 启动回溯算法，从数字 1 开始查找
		backtracking(n, k, 0, 1);
		return result; // 返回找到的所有组合
	}
};

int main() {
	Solution solution; // 创建 Solution 的实例
	int k = 3; // 设置需要选择的数字个数
	int n = 9; // 设置目标和
	// 获取所有符合条件的组合
	vector<vector<int>> combinations = solution.combinationSum3(k, n);

	// 输出结果
	for (const auto& combination : combinations) { // 遍历每一个组合
		for (int num : combination) { // 遍历组合中的每个数字
			cout << num << " "; // 输出数字
		}
		cout << endl; // 输出换行
	}

	return 0; // 程序结束
}

