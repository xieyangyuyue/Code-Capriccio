#include<iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	//map key值为[]内值，value为map[]
	// 计算四个数组中元素两两相加的和为零的组合数量
	int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
		std::unordered_map<int, int> map; // 使用 unordered_map 来存储和及其出现的次数
		int res = 0; // 用于存储最终的结果

		// 遍历数组 A 和 B，计算它们的和，并记录出现的次数
		for (int i = 0; i < (int)A.size(); i++) {
			for (int j = 0; j < (int)B.size(); j++) {
				int sumAB = A[i] + B[j]; // 计算 A[i] 和 B[j] 的和
				map[sumAB]++; // 如果和已经存在，则增加计数；如果不存在，则添加新条目
			}
		}

		// 遍历数组 C 和 D，计算它们的和，并从结果中减去已记录的和
		for (int i = 0; i < (int)C.size(); i++) {
			for (int j = 0; j < (int)D.size(); j++) {
				int sumCD = -(C[i] + D[j]); // 计算 -(C[i] + D[j])
				if (map.find(sumCD) != map.end()) {
					res += map[sumCD]; // 如果 -(C[i] + D[j]) 存在于 map 中，则增加结果
				}
			}
		}

		// 返回最终的结果
		return res;
	}
};

int main() {
	// 示例数组
	std::vector<int> A = {1, 2};
	std::vector<int> B = {-2, -1};
	std::vector<int> C = {-1, 2};
	std::vector<int> D = {0, 2};

	Solution solution;
	int result = solution.fourSumCount(A, B, C, D);
	std::cout << "The number of combinations is: " << result << std::endl;
	return 0;
}

