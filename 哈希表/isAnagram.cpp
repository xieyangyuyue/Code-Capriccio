#include <iostream>
#include <string>

bool isAnagram(std::string s, std::string t) {
	int record[26] = {0};
	int length = s.size();
	for (int i = 0; i < length; i++) {
		// 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
		record[s[i] - 'a']++;
	}
	for (int i = 0; i < length; i++) {
		record[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (record[i] != 0) {
			// record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
			return false;
		}
	}
	// record数组所有元素都为零0，说明字符串s和t是字母异位词
	return true;
}

int main() {
	std::string s = "anagram";
	std::string t = "nagaram";
	if (isAnagram(s, t)) {
		std::cout << s << " and " << t << " are anagrams." << std::endl;
	} else {
		std::cout << s << " and " << t << " are not anagrams." << std::endl;
	}

	return 0;
}

