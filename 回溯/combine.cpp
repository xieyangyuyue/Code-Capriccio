#include<iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<int>> result; // 存放符合条件结果的集合
	vector<int> path; // 用来存放符合条件结果

	// 回溯函数
	void backtracking(int n, int k, int startIndex) {
		// 如果path的大小等于k，说明找到了一个有效的组合
		if ((int)path.size() == k) {
			result.push_back(path); // 将当前组合添加到结果集中
			return;
		}
		// 从startIndex开始循环到n
		for (int i = startIndex; i <= n - (k - (int)path.size()) + 1; i++) {
			path.push_back(i); // 将当前数字添加到路径中
			backtracking(n, k, i + 1); // 递归调用，注意i+1，表示下一个数字的起始位置
			path.pop_back(); // 回溯，撤销上一次的选择
		}
	}

public:
// 主函数，生成组合
	vector<vector<int>> combine(int n, int k) {
		result.clear(); // 清空结果集，这一步其实可以省略，因为result是私有成员，每次调用combine都会重新初始化
		path.clear();   // 清空路径，这一步其实也可以省略，因为path也是私有成员，每次调用backtracking都会重新初始化
		backtracking(n, k, 1); // 从1开始回溯
		return result; // 返回最终的结果集
	}
};

// 示例用法
int main() {
	Solution solution;
	int n = 4;
	int k = 2;
	vector<vector<int>> combinations = solution.combine(n, k);

	// 输出结果
	for (const auto& combination : combinations) {
		for (int num : combination) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}

