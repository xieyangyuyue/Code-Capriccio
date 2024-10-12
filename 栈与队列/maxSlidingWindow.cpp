#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> // 用于 std::max 函数

using namespace std;

class Solution {
private:
	class MyQueue { // 单调队列（从大到小）
	public:
		deque<int> que; // 使用 deque 来实现单调队列
// 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
// 同时 pop 之前判断队列当前是否为空。
		void pop(int value) {
			if (!que.empty() && value == que.front()) {
				que.pop_front();
			}
		}
// 如果 push 的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到 push 的数值小于等于队列入口元素的数值为止。
// 这样就保持了队列里的数值是单调从大到小的了。
		void push(int value) {
			while (!que.empty() && value > que.back()) {
				que.pop_back();
			}
			que.push_back(value);
		}
// 查询当前队列里的最大值 直接返回队列前端也就是 front 就可以了。
		int front() {
			return que.front();
		}
	};
public:
// 计算数组中每个长度为 k 的滑动窗口的最大值
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MyQueue que;
		vector<int> result;
		int size = nums.size();
		for (int i = 0; i < k; i++) { // 先将前 k 的元素放进队列
			que.push(nums[i]);
		}
		result.push_back(que.front()); // result 记录前 k 的元素的最大值
		for (int i = k; i < size; i++) {
			int frontNum = nums[i - k];
			int backNum = nums[i];
			que.pop(frontNum); // 滑动窗口移除最前面元素
			que.push(backNum); // 滑动窗口前加入最后面的元素
			result.push_back(que.front()); // 记录对应的最大值
		}
		return result;
	}
};

public:
// 计算数组中每个长度为 k 的滑动窗口的最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	MyQueue que;
	vector<int> result;
	int size = nums.size();
	for (int i = 0; i < k; i++) { // 先将前 k 的元素放进队列
		que.push(nums[i]);
	}
	result.push_back(que.front()); // result 记录前 k 的元素的最大值
	for (int i = k; i < size; i++) {
		int frontNum = nums[i - k];
		int backNum = nums[i];
		que.pop(frontNum); // 滑动窗口移除最前面元素
		que.push(backNum); // 滑动窗口前加入最后面的元素
		result.push_back(que.front()); // 记录对应的最大值
	}
	return result;
}

};

int main() {
	// 创建一个测试数组
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	Solution solution;
	vector<int> result = solution.maxSlidingWindow(nums, k);

	// 输出结果
	cout << "Maximum values in sliding windows:" << endl;
	for (int val : result) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

