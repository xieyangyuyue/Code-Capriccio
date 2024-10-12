#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 用于存储每个子串是否是回文的布尔矩阵
vector<vector<bool>> isPalindrome;

// 计算所有子串是否为回文
void computePalindrome(const string& s) {
	// 根据字符串 s 的长度初始化布尔矩阵，并将所有值设为 false
	isPalindrome.resize(s.size(), vector<bool>(s.size(), false));

	// 外层循环从后向前遍历字符串
	for (int i = s.size() - 1; i >= 0; i--) {
		// 内层循环从当前 i 到字符串的末尾 j
		for (int j = i; j < (int)s.size(); j++) {
			// 如果 i 和 j 相等，表示是单个字符，直接设为 true
			if (j == i) {
				isPalindrome[i][j] = true; // 单个字符是回文
			}
			// 如果 j - i == 1，表示是两个字符，检查这两个字符是否相等
			else if (j - i == 1) {
				isPalindrome[i][j] = (s[i] == s[j]); // 两个字符相等则是回文
			}
			// 对于三个或更多字符的子串，通过检查两端字符和内部的子串是否是回文
			else {
				// 字符 s[i] 和 s[j] 必须相等，并且内部子串 s[i+1:j-1] 也要是回文
				isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
			}
		}
	}
}

// 主函数，程序入口
int main() {
	string s = "abacaba"; // 定义要检查的字符串
	computePalindrome(s); // 计算字符串中所有子串是否为回文

	// 输出结果，打印布尔矩阵
	for (size_t i = 0; i < isPalindrome.size(); i++) {
		for (size_t j = 0; j < isPalindrome[i].size(); j++) {
			cout << (isPalindrome[i][j] ? "T " : "F "); // 如果是回文则输出 'T'，否则输出 'F'
		}
		cout << endl; // 换行
	}

	return 0; // 结束程序
}

