#include <iostream>

// 链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};
//双指针
ListNode* reverseList(ListNode* head) {
	ListNode* temp; // 保存cur的下一个节点
	ListNode* cur = head;
	ListNode* pre = NULL;
	while (cur) {
		temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
		cur->next = pre; // 翻转操作
		// 更新pre 和 cur指针
		pre = cur;
		cur = temp;
	}
	return pre;
}
//迭代
ListNode* reverse(ListNode* pre, ListNode* cur) {
	if (cur == NULL) return pre;
	ListNode* temp = cur->next;
	cur->next = pre;
	// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
	// pre = cur;
	// cur = temp;
	return reverse(cur, temp);
}
ListNode* reverseList1(ListNode* head) {
	// 和双指针法初始化是一样的逻辑
	// ListNode* cur = head;
	// ListNode* pre = NULL;
	return reverse(NULL, head);
}
void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main() {
	// 创建一个测试链表 1 -> 2 -> 3 -> 4 -> 5
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	std::cout << "Original list: ";
	printList(head);

	// 反转链表
	head = reverseList1(head);
	std::cout << "Reversed list: ";
	printList(head);

	// 释放链表内存
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}

