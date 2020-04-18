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

	void infixOrder(TreeNode* root);  //中序遍历
	void preOrder(TreeNode* root);    //前序遍历
	void postOrder(TreeNode* root);   //后续遍历

	vector<int> inorderTraversal(TreeNode* root);
	vector<TreeNode*> generateTrees(int n);
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	inline TreeNode* getRoot() { return _root; }
private:
	TreeNode *_root;
	size_t _height;
	size_t _size; //node 个数
	vector<int> _infixRet;
};