#include <iostream>
#include <queue>

using namespace std;

//两个队列实现
//class MyStack {
//public:
//	queue<int> que1;
//	queue<int> que2; // 辅助队列，用来备份
//
//	/** Initialize your data structure here. */
//	MyStack() {
//	}
//
//	/** Push element x onto stack. */
//	void push(int x) {
//		que1.push(x);
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop() {
//		int size = que1.size();
//		size--;
//		while (size--) { // 将que1 导入que2，但要留下最后一个元素
//			que2.push(que1.front());
//			que1.pop();
//		}
//
//		int result = que1.front(); // 留下的最后一个元素就是要返回的值
//		que1.pop();
//		que1 = que2;            // 再将que2赋值给que1
//		while (!que2.empty()) { // 清空que2
//			que2.pop();
//		}
//		return result;
//	}
//
//	/** Get the top element. */
//	int top() {
//		return que1.back();
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty() {
//		return que1.empty();
//	}
//};

//一个队列实现
class MyStack {
public:
	queue<int> que;
	/** Initialize your data structure here. */
	MyStack() {

	}
	/** Push element x onto stack. */
	void push(int x) {
		que.push(x);
	}
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = que.size();
		size--;
		while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
			que.push(que.front());
			que.pop();
		}
		int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
		que.pop();
		return result;
	}

	/** Get the top element. */
	int top() {
		return que.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return que.empty();
	}
};
int main() {
	MyStack stack;

	// 测试 push 操作
	stack.push(1);
	stack.push(2);
	stack.push(3);

	// 测试 top 操作
	cout << "Top: " << stack.top() << endl; // 输出 3

	// 测试 pop 操作
	cout << "Pop: " << stack.pop() << endl; // 输出 3
	cout << "Pop: " << stack.pop() << endl; // 输出 2

	// 测试 empty 操作
	cout << "Is empty: " << stack.empty() << endl; // 输出 0 (false)

	return 0;
}

