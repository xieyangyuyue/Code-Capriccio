#include <iostream>
#include <vector>
#include <algorithm> // 用于 swap 函数

class Solution {
public:
	// 反转字符向量 s
	void reverseString(std::vector<char>& s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			// 使用 std::swap 函数交换 s[left] 和 s[right]
			std::swap(s[left], s[right]);
			left++;
			right--;
		}
		// 返回，因为不需要任何额外的操作
		return;
	}
	void reverseString1(std::vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};

int main() {
	// 创建一个测试字符向量
	std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original string: ";
	for (char c : s) {
		std::cout << c;
	}
	std::cout << std::endl;

	// 反转字符向量
	Solution solution;
	solution.reverseString(s);
	std::cout << "Reversed string: ";
	for (char c : s) {
		std::cout << c;
	}
	std::cout << std::endl;

	return 0;
}

