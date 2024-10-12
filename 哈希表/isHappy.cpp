#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
	// 判断一个整数是否是快乐数
	bool isHappy(int n) {
		// 使用 unordered_set 来记录已经出现的数，以便快速判断是否重复
		std::unordered_set<int> set;
		// 当 n 不是 1 且 set 中没有 n 时，继续循环
		while (n != 1 && set.find(n) == set.end()) {
			// 将 n 插入到 set 中
			set.insert(n);
			// 计算 n 的下一个数
			n = getNextNumber(n);
		}
		// 如果 n 最终等于 1，则 n 是快乐数，返回 true
		return n == 1;
	}

	// 计算 n 的下一个数
	int getNextNumber(int n) {
		int res = 0;
		// 遍历 n 的每一位数字
		while (n > 0) {
			int temp = n % 10;
			// 将每位数字的平方加到结果上
			res += temp * temp;
			// 去除 n 的最后一位数字
			n /= 10;
		}
		// 返回计算出的下一个数
		return res;
	}
};

int main() {
	Solution solution;
//	int num = 19; // 示例整数
//	if (solution.isHappy(num)) {
//		std::cout << num << " is a happy number." << std::endl;
//	} else {
//		std::cout << num << " is not a happy number." << std::endl;
//	}
	for (int i = 0; i < 100; i++) {
		if (solution.isHappy((i))) {
			cout << i << ' ';
		}
	}
	return 0;
}

