#pragma once

#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkList
{
public:
	LinkList() : _head(nullptr), _len(0) {};
	virtual ~LinkList() {};
	LinkList addToTail(ListNode& node);
	LinkList delHead();
	ListNode* getHead();
	LinkList getInitList(int, int);
	LinkList removeNthFromEnd(ListNode* head, int n);
	LinkList mergeTwoLists(ListNode* l1, ListNode* l2);
	LinkList mergeKLists(vector<ListNode*>& lists);
	LinkList swapPairs(ListNode* head);
	LinkList reverseKGroup(ListNode* head, int k);
	LinkList show();

private:
	ListNode* _head;
	ListNode* _tail;
	size_t _len;
};

