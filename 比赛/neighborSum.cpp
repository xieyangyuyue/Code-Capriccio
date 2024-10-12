#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class neighborSum {
private:
	int n;
	vector<vector<int>> grid;
	unordered_map<int, vector<pair<int, int>>> positionMap;
	
public:
	neighborSum(vector<vector<int>>& grid) {
		this->grid = grid;
		n = grid.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int value = grid[i][j];
				positionMap[value].push_back({i, j});
			}
		}
	}
	
	int adjacentSum(int value) {
		int sum = 0;
		vector<pair<int, int>> positions = positionMap[value];
		for (const auto& pos : positions) {
			int x = pos.first;
			int y = pos.second;
			if (x > 0) sum += grid[x - 1][y]; // 上
			if (x < n - 1) sum += grid[x + 1][y]; // 下
			if (y > 0) sum += grid[x][y - 1]; // 左
			if (y < n - 1) sum += grid[x][y + 1]; // 右
		}
		return sum;
	}
	
	int diagonalSum(int value) {
		int sum = 0;
		vector<pair<int, int>> positions = positionMap[value];
		for (const auto& pos : positions) {
			int x = pos.first;
			int y = pos.second;
			if (x > 0 && y > 0) sum += grid[x - 1][y - 1]; // 左上
			if (x > 0 && y < n - 1) sum += grid[x - 1][y + 1]; // 左下
			if (x < n - 1 && y > 0) sum += grid[x + 1][y - 1]; // 右上
			if (x < n - 1 && y < n - 1) sum += grid[x + 1][y + 1]; // 右下
		}
		return sum;
	}
};

int main() {
	vector<vector<int>> grid = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
	neighborSum obj(grid);
	cout << obj.adjacentSum(1) << endl; // 输出相邻元素之和
	cout << obj.adjacentSum(4) << endl; // 输出相邻元素之和
	cout << obj.diagonalSum(4) << endl; // 输出对角线相邻元素之和
	cout << obj.diagonalSum(8) << endl; // 输出对角线相邻元素之和
	return 0;
}

