#include <iostream>

// 链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

//设置一个虚拟头结点在进行删除操作
ListNode* removeElements(ListNode* head, int val) {
	ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
	dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
	ListNode* cur = dummyHead;
	while (cur->next != NULL) {
		if (cur->next->val == val) {
			ListNode* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		} else {
			cur = cur->next;
		}
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;
}

//直接使用原来的链表来进行删除操作
ListNode* removeElements1(ListNode* head, int val) {
	// 删除头结点
	while (head != NULL && head->val == val) { // 注意这里不是if
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}

	// 删除非头结点
	ListNode* cur = head;
	while (cur != NULL && cur->next != NULL) {
		if (cur->next->val == val) {
			ListNode* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		} else {
			cur = cur->next;
		}
	}
	return head;
}

void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main() {
	// 创建一个测试链表 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
	std::cout << "Original list: ";
	printList(head);

	// 删除所有值为 6 的节点
	head = removeElements(head, 6);
	std::cout << "After removal: ";
	printList(head);

	// 释放链表内存
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}

