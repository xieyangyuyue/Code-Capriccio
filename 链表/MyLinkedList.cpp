#include <iostream>
// 链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class MyLinkedList {
public:
	MyLinkedList() {
		// 初始化
		this->size = 0;
		this->head = new ListNode(0);
	}
	int get(int index) {
		// 校验合法
		if (index < 0 || index >= size)
			return -1;
		// 生成临时节点指向头节点
		ListNode* cur = head;
		for (int i = 0; i <= index; i++) {
			cur = cur->next;
		}
		return cur->val;
	}
	void addAtHead(int val) { addAtIndex(0, val); }
	void addAtTail(int val) { addAtIndex(size, val); }
	void addAtIndex(int index, int val) {
		// 参数校验
		if (index < 0 || index > size)
			return;
		// 长度增加
		size++;
		// 虚拟节点指向头结点，使之指向插入位置的前一个结点
		ListNode* pre = head;
		for (int i = 0; i < index; i++)
			pre = pre->next;
		// 为插入值生成结点
		ListNode* toAdd = new ListNode(val);
		toAdd->next = pre->next;
		pre->next = toAdd;
	}
	void deleteAtIndex(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		size--;
		ListNode* pred = head;
		for (int i = 0; i < index; i++) {
			pred = pred->next;
		}
		// p指向要删除结点
		ListNode* p = pred->next;
		pred->next = pred->next->next;
		delete p;
	}
private:
	int size;       // 大小
	ListNode* head; // 结点
};
int main() {
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(1);
	obj->addAtTail(3);
	obj->addAtIndex(1, 2); // 链表变为1-> 2-> 3
	std::cout << "Element at index 1: " << obj->get(1) << std::endl; // 返回2
	obj->deleteAtIndex(1); // 链表变为1-> 3
	std::cout << "Element at index 1 after deletion: " << obj->get(1) << std::endl; // 返回3
	// 清理链表
	delete obj;
	return 0;
}


