#include <iostream>
#include <vector>
#include <stack>
#include <cmath> // 用于 stoll 函数

using namespace std;

class Solution {
public:
	// 计算后缀表达式的结果
	long long evalRPN(vector<string>& tokens) {
		stack<long long> st; // 使用 long long 类型以处理大整数
		int size = tokens.size();
		for (int i = 0; i < size; i++) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				long long num1 = st.top();
				st.pop();
				long long num2 = st.top();
				st.pop();
				if (tokens[i] == "+") st.push(num2 + num1);
				if (tokens[i] == "-") st.push(num2 - num1);
				if (tokens[i] == "*") st.push(num2 * num1);
				if (tokens[i] == "/") st.push(num2 / num1);
			} else {
				st.push(stoll(tokens[i])); // 将字符串转换为长整数并压入栈中
			}
		}
		// 栈中只有一个元素，即计算结果
		long long result = st.top();
		st.pop(); // 弹出栈顶元素（其实不弹出也没事）
		return result;
	}
};

int main() {
	// 创建一个测试后缀表达式的数组
	vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	Solution solution;
	long long result = solution.evalRPN(tokens);

	// 输出结果
	cout << "Result: " << result << endl;

	return 0;
}

