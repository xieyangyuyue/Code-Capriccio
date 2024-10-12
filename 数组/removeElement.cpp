#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
	int slow = 0, fast = 0, n = nums.size() - 1; //一对夫妇，原本都是零起点
	while (fast < n) {   //但是有一个跑得快，一个跑得慢
		if (nums[fast] != val) {    //于是跑得快的那个先去寻找共同目标
			nums[slow] = nums[fast];    //如果找到了，就送给跑得慢的那个
			slow++;     //然后跑得慢的那个也就离目标近一点
		}
		fast++; //但是不管是否找得到，跑得快的那方都一直奔跑到生命的尽头
	}
	return slow;    //最终留下跑得慢的一方
}
int removeElement1(std::vector<int>&nums, int val) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] == val) {
			for (int j = i + 1; j < n; j++) {
				nums[j - 1] = nums[j];
			}
			i--;
			n--;
		}
	}
	return n;
}

int main() {
	std::vector<int> nums = {3, 2, 2, 3};
//	std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 3;

	int newLength = removeElement(nums, val);

	std::cout << "新数组的长度为: " << newLength << std::endl;
	for (int i = 0; i < newLength; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

