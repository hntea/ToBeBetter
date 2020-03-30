#include "LinkList.h"


LinkList LinkList::addToTail(ListNode& node)
{
	if (_head == NULL) {
		_head = &node;
		_head->next = _tail;
		_tail = &node;
	}
	else {
#if 0
		ListNode* p = _head;
		for (int i = 0; i < _len; i++) {
			if (p->next == nullptr) {
				p->next = &node;
				break;
			}
			p = p->next;
		}
#endif
		_tail->next = &node;
		_tail = &node;
	}
	_len++;
	return *this;
}

LinkList LinkList::delHead()
{
	if (_head != nullptr) {
		ListNode* temp = _head;
		_head = _head->next;
		_len--;
		delete temp;
	}
	return *this;
}

ListNode* LinkList::getHead() {
	return _head;
}

LinkList LinkList::show() {

	if (_head == nullptr) {
		cout << "Invalid argumet" << endl;
		return *this;
	}

	ListNode* point = _head;
	int len = _len;

	while (point->next != nullptr) {
		cout << point->val << "->";
		point = point->next;
	}
	cout << point->val << endl;
	return *this;
}

LinkList LinkList::getInitList(int start, int end) {

	for (int j = start; j < end; j++) {
		ListNode* p = new ListNode(j);
		this->addToTail(*p);
	}
	return *this;
}


/*
19. 删除链表的倒数第N个节点(done)
删除链表的倒数第 n 个节点，并且返回链表的头结点。
*/
LinkList LinkList::removeNthFromEnd(ListNode* head, int n)
{
	size_t len = 0;
	ListNode* tmp = head;
	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	/*1.get size*/
	while (tmp != nullptr) {
		tmp = tmp->next;
		len++;
	}


	len -= n;
	std::cout << "target index is: " << len << endl;
	tmp = dummy;
	while (len-- > 0) {
		tmp = tmp->next;
	}
	tmp->next = tmp->next->next;
	_head = dummy->next;

	return *this;
}

/*
21. 合并两个有序链表 (done)
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

*/
LinkList LinkList::mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode* A = l1;
	ListNode* B = l2;

	ListNode* root = new ListNode(-1);
	root->next = A;

	ListNode* cur = root->next;
	ListNode* prv = root;
	ListNode* temp = nullptr;
	while (A&&B)
	{
		if (A->val <= B->val)
		{
			prv = cur;
			cur = cur->next;
			A = cur;
		}
		else {
			prv->next = B;
			temp = B->next;
			B->next = cur;
			prv = B;
			B = temp;
		}
	}

	(!A && B) ? prv->next = B : prv->next = A;
	_head = root->next;
	return *this;
}

/*
24. 两两交换链表中的节点(done)
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
LinkList LinkList::swapPairs(ListNode* head)
{
	ListNode* pRoot = new ListNode(-1);
	pRoot->next = head;
	ListNode* prv = pRoot;
	ListNode* A = nullptr;
	ListNode* B = nullptr;
	ListNode* C = nullptr;

	while (prv->next != nullptr && prv->next->next != nullptr) {
		A = prv->next;
		B = A->next;
		C = B->next;

		prv->next = B;
		B->next = A;
		A->next = C;

		prv = A;
	}

	_head = pRoot->next;

	return *this;
}



/*
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

题解思路
方法一：1&2 合并后再和 3 合并
方法二：分治，1&2 合并，3&4合并 .. 最终合并 （分治排序的思想）
*/
LinkList LinkList::mergeKLists(vector<ListNode*>& lists) {


	ListNode* root = new ListNode(-1);
	if (lists.size() == 0) {
		return *this;
	}
	root->next = lists[0];

	ListNode* a = nullptr;
	ListNode* b = nullptr;
	ListNode* temp = nullptr;
	a = lists[0];
	ListNode* prv = root;
	ListNode* cur = root->next;

	for (int i = 1; i < lists.size(); i++) {
		b = lists[i];
		while (a&&b)
		{
			if (a->val <= b->val) {
				prv = cur;
				cur = cur->next;
				a = cur;
			}
			else {
				prv->next = b;
				temp = b->next;
				b->next = a;
				prv = b;
				b = temp;
			}
		}

		(!a && b) ? prv->next = b : prv->next = a;
		a = root->next;
		prv = root;
		cur = root->next;
	}

	_head = root->next;

	return *this;
}

/*

*/
LinkList LinkList::reverseKGroup(ListNode* head, int k)
{
	if (head == nullptr || k <= 1) {
		return *this;
	}

	ListNode* root = new ListNode(-1);
	root->next = head;

	ListNode* cur = root;
	ListNode* prv = root;
	ListNode* a = nullptr;
	ListNode* b = nullptr;
	ListNode* temp = nullptr;

	while (cur) {

		/*1.move cur to K*/
		prv = cur;
		for (int i = 0; i < k; i++) {
			cur = cur->next;
			if (cur == nullptr)
			{
				_head = root->next;
				return *this;
			}
		}
		
		a = prv->next;
		b = cur->next;

		/*2.swap*/
		temp = prv;
		prv = cur;
		cur = temp;

		prv->next = b;
		cur->next = a;

		/*move head*/
		cur = b;
	}
	_head = root->next;

	return *this;
}