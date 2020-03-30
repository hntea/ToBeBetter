#include "LinkSolutionTest.h"
#include "LinkList.h"
#include <iostream>
#include <vector>
using namespace std;

LinkSolutionTest::LinkSolutionTest()
{
}


LinkSolutionTest::~LinkSolutionTest()
{
}

void LinkSolutionTest::run() {
#if 0
	cout << "Hello Link Solution Test" << endl;
	cout << endl << "Merge K link list " << endl;
	LinkList a;
	a.getInitList(1, 5).show();
	LinkList b;
	b.getInitList(3, 8).show();
	LinkList c;
	c.getInitList(10, 15).show();
	LinkList d;
	d.getInitList(40, 42).show();

	LinkList e;
	e.getInitList(13, 16).show();

	vector<ListNode*> lists;
	lists.push_back(a.getHead());
	lists.push_back(b.getHead());
	lists.push_back(c.getHead());
	lists.push_back(d.getHead());
	lists.push_back(e.getHead());
	a.mergeKLists(lists).show();
#endif
	LinkList a;
	a.getInitList(0, 5).show();
	a.reverseKGroup(a.getHead(), 3).show();
}