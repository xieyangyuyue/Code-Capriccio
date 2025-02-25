#include<bits/stdc++.h>
using namespace std;

void test_2_wei_bag_problem1() {
	vector<int> weight = {1, 3, 4};
	vector<int> value = {15, 20, 30};
	int bagweight = 4;

	// 二维数组
	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

	// 初始化
	for (int j = weight[0]; j <= bagweight; j++) {
		dp[0][j] = value[0];
	}

	// weight数组的大小 就是物品个数
	for (int i = 1; i < (int)weight.size(); i++) { // 遍历物品
		for (int j = bagweight; j>=weight[i]; j--) { // 遍历背包容量
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

		}
	}

	cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
	test_2_wei_bag_problem1();
}
