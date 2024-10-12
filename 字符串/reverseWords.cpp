#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	// 反转字符串中的单词顺序
//	std::string reverseWords(std::string s) {
//		// 使用双指针
//		int m = s.size() - 1;
//		std::string res;
//		// 除去尾部空格
//		while (s[m] == ' ' && m > 0) m--;
//		int n = m; // n是另一个指针
//		while (m >= 0) {
//			while (m >= 0 && s[m] != ' ') m--;
//			res += s.substr(m + 1, n - m) + " "; // 获取单词并加上空格
//			while (m >= 0 && s[m] == ' ') m--;
//			n = m;
//		}
//		res = res.substr(0, res.size() - 1); // 忽略最后一位的空格
//		return res;
//	}
	string reverseWords1(string s) {
		string result;
		int m=s.size()-1;
		while(s[m]==' '&&m>0)m--;
		int n=m;//词尾
		while(m>=0){
			while(s[m]!=' '&&m>=0)m--;//空格
			result+=s.substr(m+1,n-m)+' ';
			while(s[m]==' '&&m>=0)m--;
			n=m;
		}
		return result.substr(0,s.size()-1);
	}
};

int main() {
	// 创建一个测试字符串
	std::string s = "  hello world  ";
	Solution solution;
	std::string result = solution.reverseWords1(s);

	// 输出结果
	std::cout << "Original string: " << s << std::endl;
	std::cout << "Reversed string: " << result << std::endl;

	return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
//		for (int i = start, j = end; i < j; i++, j--) {
//			swap(s[i], s[j]);
//		}
//	}
//	
//	void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
//		int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
//		for (int i = 0; i < s.size(); ++i) { //
//			if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
//				if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
//				while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
//					s[slow++] = s[i++];
//				}
//			}
//		}
//		s.resize(slow); //slow的大小即为去除多余空格后的大小。
//	}
//	
//	string reverseWords(string s) {
//		removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
//		reverse(s, 0, s.size() - 1);
//		int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
//		for (int i = 0; i <= s.size(); ++i) {
//			if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
//				reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
//				start = i + 1; //更新下一个单词的开始下标start
//			}
//		}
//		return s;
//	}
//};
//int main() {
//	// 创建一个测试字符串
//	std::string s = "  hello world  ";
//	Solution solution;
//	std::string result = solution.reverseWords(s);
//	
//	// 输出结果
//	std::cout << "Original string: " << s << std::endl;
//	std::cout << "Reversed string: " << result << std::endl;
//	
//	return 0;
//}
