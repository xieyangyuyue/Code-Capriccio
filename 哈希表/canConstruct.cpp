#include <iostream>
#include <string>

class Solution {
public:
	// 判断一个赎金信字符串是否可以由另一个杂志字符串中的字符构成
	bool canConstruct(std::string ransomNote, std::string magazine) {
		int record[26] = {0}; // 创建一个数组来记录杂志中每个字符出现的次数
		// 如果赎金信的长度大于杂志的长度，则无法构成
		if (ransomNote.size() > magazine.size()) {
			return false;
		}
		// 遍历杂志字符串，记录每个字符的出现次数
		for (int i = 0; i < magazine.length(); i++) {
			record[magazine[i] - 'a']++;
		}
		// 遍历赎金信字符串，对记录中相应字符的出现次数进行减一操作
		for (int j = 0; j < ransomNote.length(); j++) {
			record[ransomNote[j] - 'a']--;
			// 如果字符出现次数小于零，说明杂志中没有足够的字符来构成赎金信
			if (record[ransomNote[j] - 'a'] < 0) {
				return false;
			}
		}
		// 如果所有字符都成功减一，没有出现负数，则可以构成赎金信
		return true;
	}
	
	public:
		bool canConstruct1(std::string ransomNote, std::string magazine) {
			for (int i = 0; i < magazine.length(); i++) {
				for (int j = 0; j < ransomNote.length(); j++) {
					// 在ransomNote中找到和magazine相同的字符
					if (magazine[i] == ransomNote[j]) {
						ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
						break;
					}
				}
			}
			// 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
			if (ransomNote.length() == 0) {
				return true;
			}
			return false;
		}
	
};

int main() {
	Solution solution;
	std::string ransomNote = "aa";
	std::string magazine = "aab";
	if (solution.canConstruct1(ransomNote, magazine)) {
		std::cout << "The ransom note can be constructed from the magazine." << std::endl;
	} else {
		std::cout << "The ransom note cannot be constructed from the magazine." << std::endl;
	}
	return 0;
}

