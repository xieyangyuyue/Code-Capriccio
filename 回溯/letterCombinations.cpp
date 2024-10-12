#include <iostream> // 引入输入输出库
#include <vector>   // 引入向量（动态数组）库
#include <string>   // 引入字符串库

using namespace std; // 使用标准命名空间

class Solution {
private:
	const string letterMap[10] = {
		"",     // 0 没有对应字母
		"",     // 1 没有对应字母
		"abc",  // 2 对应的字母
		"def",  // 3 对应的字母
		"ghi",  // 4 对应的字母
		"jkl",  // 5 对应的字母
		"mno",  // 6 对应的字母
		"pqrs", // 7 对应的字母
		"tuv",  // 8 对应的字母
		"wxyz"  // 9 对应的字母
	};

public:
	vector<string> result; // 存储结果组合的向量
	string s;             // 当前组合的字符串

	// 回溯函数
	void backtracking(const string& digits, int index) {
		// 如果当前索引等于输入数字的长度，说明已经生成一个有效的组合
		if (index == (int)digits.size()) {
			result.push_back(s); // 将当前组合添加到结果中
			return; // 返回
		}

		// 获取当前数字所对应的字母
		int digit = digits[index] - '0'; // 将字符转为数字
		string letters = letterMap[digit]; // 获取该数字对应的字母串

		// 遍历所有可能的字母
		for (int i = 0; i < (int)letters.size(); i++) {
			s.push_back(letters[i]); // 添加当前字母到组合
			backtracking(digits, index + 1); // 递归调用，处理下一个数字
			s.pop_back(); // 回溯，移除最后一个字母
		}
	}

	// 主函数，用于获取字母组合
	vector<string> letterCombinations(string digits) {
		s.clear(); // 清空当前组合
		result.clear(); // 清空结果集

		if (digits.size() == 0) { // 如果输入为空，直接返回结果
			return result;
		}

		backtracking(digits, 0); // 启动回溯搜索，从第一个数字开始
		return result; // 返回找到的所有组合
	}
};

int main() {
	Solution solution; // 创建 Solution 对象

	string input = "23"; // 输入字符串
	vector<string> combinations = solution.letterCombinations(input); // 获取字母组合

	// 输出结果
	cout << "所有可能的字母组合：" << endl;
	for (const string& combination : combinations) { // 遍历并打印每个组合
		cout << combination << " ";
	}
	cout << endl;

	return 0; // 程序结束
}

