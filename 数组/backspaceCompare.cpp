#include <iostream>
#include <string>

class Solution {
public:
	std::string build(std::string str) {
		std::string ret;
		for (char ch : str) {
			if (ch != '#') {
				ret.push_back(ch);
			} else if (!ret.empty()) {
				ret.pop_back();
			}
		}
		return ret;
	}
	
	bool backspaceCompare(std::string s, std::string t) {
		return build(s) == build(t);
	}
};

int main() {
	Solution solution;
	std::string s = "ab#c";
	std::string t = "ad#c";
	
	bool result = solution.backspaceCompare(s, t);
	if (result) {
		std::cout << "The strings are equal after backspace processing." << std::endl;
	} else {
		std::cout << "The strings are not equal after backspace processing." << std::endl;
	}
	
	return 0;
}


