#include <iostream>
#include <string>
#include <stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	// 移除字符串中的重复字符
	string removeDuplicates(string S) {
		stack<char> st;
		for (char s : S) {
			if (st.empty() || s != st.top()) {
				st.push(s);
			} else {
				st.pop(); // s 与 st.top()相等的情况
			}
		}
		string result = "";
		while (!st.empty()) { // 将栈中元素放到result字符串汇总
			result += st.top();
			st.pop();
		}
		reverse (result.begin(), result.end()); // 此时字符串需要反转一下
		return result;
	}

public:
	string removeDuplicates1(string S) {
		string result;
		for (char s : S) {
			if (result.empty() || result.back() != s) {
				result.push_back(s);
			} else {
				result.pop_back();
			}
		}
		return result;
	}

};

int main() {
	Solution solution;
	string s = "aaabbbccc";
	string result = solution.removeDuplicates1(s);
	cout << "Result: " << result << endl;
	return 0;
}

