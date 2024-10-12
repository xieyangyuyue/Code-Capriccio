#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility> // for std::pair

using namespace std;

class Solution {
public:
	// 定义一个比较类，用于小顶堆的比较规则
	class mycomparison {
	public:
		// 重载()运算符，使得优先队列按照pair的second值（即频率）升序排列
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
			return lhs.second > rhs.second; // 如果左边的second大于右边的second，则左边的优先级低
		}
	};

	// 主函数，返回数组中出现频率最高的k个元素
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// 统计每个元素的出现频率
		unordered_map<int, int> map; // 使用哈希表记录每个元素及其出现的次数
		for (int num : nums) {
			map[num]++; // 对应元素频率加1
		}

		// 定义一个小顶堆，用于维护出现频率最高的k个元素
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

		// 遍历哈希表，将元素及其频率放入小顶堆中
		for (auto it = map.begin(); it != map.end(); ++it) {
			pri_que.push(*it); // 将当前元素及其频率放入堆中
			if ((int)pri_que.size() > k) { // 如果堆的大小超过k，则弹出堆顶元素
				pri_que.pop();
			}
		}

		// 从小顶堆中取出前k个高频元素，由于堆顶元素是频率最小的，所以需要倒序放入结果数组
		vector<int> result(k);
		for (int i = k - 1; i >= 0; --i) {
			result[i] = pri_que.top().first; // 获取堆顶元素的键（即数组中的元素）
			pri_que.pop(); // 弹出堆顶元素
		}
		return result; // 返回结果数组
	}
};

// 示例使用
int main() {
	Solution sol;
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> result = sol.topKFrequent(nums, k);
	// 输出频率最高的k个元素
	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}

