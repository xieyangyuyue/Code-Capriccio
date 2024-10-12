#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
	int top = 0;
	int bottom = n - 1;
	int left = 0;
	int right = n - 1;
	// 初始化二维数组存数据
	std::vector<std::vector<int>> ans(n, std::vector<int>(n));
	// num表示从1起始，end表示最后一个数
	int num = 1, end = n * n;
	while (num <= end) {
		// left to right
		for (int i = left; i <= right; i++) ans[top][i] = num++;
		top++;
		// top to bottom
		for (int i = top; i <= bottom; i++) ans[i][right] = num++;
		right--;
		// right to left
		for (int i = right; i >= left; i--) ans[bottom][i] = num++;
		bottom--;
		// bottom to top
		for (int i = bottom; i >= top; i--) ans[i][left] = num++;
		left++;
	}
	return ans;
}

int main() {
	int n = 3; // 可以更改这个值来生成不同大小的螺旋矩阵
	std::vector<std::vector<int>> matrix = generateMatrix(n);
	std::cout << "Generated matrix:" << std::endl;
	for (const auto& row : matrix) {
		for (int num : row) {
			std::cout << num << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}

