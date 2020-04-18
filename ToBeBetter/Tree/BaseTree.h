#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "../LinkList/LinkList.h"

using namespace std;

/* Definition for a binary tree node.*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BaseTree {
public:
	BaseTree();
	virtual ~BaseTree();
	BaseTree(std::initializer_list<int> list);
	BaseTree binaryTreeInsert(TreeNode& node);
	BaseTree sortedListToBST(ListNode* head);

	void infixOrder(TreeNode* root);  //�������
	void preOrder(TreeNode* root);    //ǰ�����
	void postOrder(TreeNode* root);   //��������

	vector<int> inorderTraversal(TreeNode* root);
	vector<TreeNode*> generateTrees(int n);
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	inline TreeNode* getRoot() { return _root; }
private:
	TreeNode *_root;
	size_t _height;
	size_t _size; //node ����
	vector<int> _infixRet;
};