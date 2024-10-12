#include <iostream>
#include <string>
#include <algorithm> // 用于 reverse 函数

class Solution {
public:
	// 将字符串 s 中的每个长度为 k 的子串反转
	std::string reverseStr(std::string s, int k) {
		int len = s.size();
		for (int i = 0; i < len; i += (2 * k)) {
			int strlen=i+k;
			if (strlen<= len) {
				// 如果还有足够的字符形成一个完整的 k 长度子串，则反转它
				std::reverse(s.begin() + i, s.begin() + i + k);
			} else {
				// 否则，反转剩余的所有字符
				std::reverse(s.begin() + i, s.end());
			}
		}
		// 返回反转后的字符串
		return s;
	}
};

int main() {
	// 创建一个测试字符串
	std::string s = "abcdefghijk";
	int k = 2;
	Solution solution;
	std::string result = solution.reverseStr(s, k);

	// 输出结果
	std::cout << "Original string: " << s << std::endl;
	std::cout << "Reversed string: " << result << std::endl;

	return 0;
}

